const express = require('express');

const { isLoggedIn } = require('./middlewares');
const User = require('../models/user');

const router = express.Router();

router.get('/test', isLoggedIn, async (req, res, next) => {
  res.send('success');
  res.locals.message = "bbbbbb";
  console.log("it's login!!!!", res.locals.message)
});

router.post('/:id/addFriend', isLoggedIn, async (req, res, next) => {
  try {
    const user = await User.findOne({ where: { id: req.user.id } });
    if (user) {
      await user.addFriend(parseInt(req.params.id, 10));
      res.send('success');
    } else {
      res.status(404).send('no user');
    }
  } catch (error) {
    console.error(error);
    next(error);
  }
});

module.exports = router;
