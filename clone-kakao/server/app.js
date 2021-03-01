const express = require('express');
const cookieParser = require('cookie-parser');
const morgan = require('morgan');
const session = require('express-session');
const dotenv = require('dotenv');

const { sequelize } = require('./models');

dotenv.config();
const authRouter = require('./routers/auth');
const userRouter = require('./routers/user');

const passportConfig = require('./passport');
const passport = require('passport');

const app = express();
passportConfig();

app.set('port', process.env.PORT || 3000);

sequelize.sync({ force: false})
    .then(() => {
        console.log("database is connected")
    })
    .catch((err) => {
        console.log(err);
    });

app.use(morgan('dev'));
app.use(express.json());
app.use(express.urlencoded({extended: false}));
app.use(cookieParser(process.env.KAKAO_COOKIE_RECIPE));

app.use(session({
    resave: false,
    saveUninitialized: false,
    secret: process.env.KAKAO_COOKIE_RECIPE,
    cookie: {
        httpOnly: true,
        secure: false,
    }
}));


app.use(passport.initialize());
app.use(passport.session());

app.get('/', (req, res) => {
    res.send('/ get');
});

app.post('/', (req, res) => {
    console.log("/ post")
});

app.use('/auth', authRouter);
app.use('/user', userRouter);


app.use((req, res, next) => {
    const error = new Error(`${req.method} ${req.url} no router`);
    error.status = 404;
    // console.log(error);
    next(error);
});

app.use((err, req, res, next) => {
    res.locals.message = err,message = err.message;
    res.locals.error = err;
    res.status(err.status || 500);
    console.log(err);
});


app.listen(app.get('port'), () => {
    console.log('waiting at ', app.get('port'), ' port');
});