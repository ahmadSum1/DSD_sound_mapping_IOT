// All things to do with firebase

var dbRef;
        // Initialize Firebase
        
        (function(){


        var config = {
            apiKey: "AIzaSyCuaS4KMpAk2DKasMSXYpj20f_77nUOu_I",
            authDomain: "iot-noise-level-dsd.firebaseapp.com",
            databaseURL: "https://iot-noise-level-dsd.firebaseio.com",
            projectId: "iot-noise-level-dsd",
            storageBucket: "iot-noise-level-dsd.appspot.com",
            // messagingSenderId: "989739738080"
        };
        firebase.initializeApp(config);
        //create instanse of my database
        var mtDatabase = firebase.database();

        //create referrence to my DB's "number" object
        dbRef = mtDatabase.ref()

        })()


