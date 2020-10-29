let scoreUserEl = document.getElementById("score-player");
let scorePCEl = document.getElementById("score-pc");
let roundResultEl = document.getElementById("roundResult");

let choices = ["Kámen", "Nůžky", "Papír"];
let userChoice = "";
let pcChoice = "";

let scorePC = 0;
let scoreUser = 0;

function validateChoice(btnId){
    switch (btnId){
        case "btnKamen":
            userChoice = "Kámen";
            break;
        case "btnNuzky":
            userChoice = "Nůžky";
            break;
        case "btnPapir":
            userChoice = "Papír";
            break;
    }

    pcChoice = choices[Math.floor(Math.random() * choices.length)];

    if (userChoice == "Kámen" && pcChoice == "Kámen"){
        roundResult.innerHTML = "remíza!";

    } else if (userChoice == "Nůžky" && pcChoice == "Kámen"){
        roundResult.innerHTML = "prohra!";
        scorePC += 1;
    } else if (userChoice == "Papír" && pcChoice == "Kámen"){
        roundResult.innerHTML = "výhra!";
        scoreUser += 1;

    } else if(userChoice == "Kámen" && pcChoice == "Nůžky"){
        roundResult.innerHTML = "výhra!";
        scoreUser += 1;

    } else if (userChoice == "Nůžky" && pcChoice == "Nůžky"){
        roundResult.innerHTML = "remíza!";

    } else if (userChoice == "Papír" && pcChoice == "Nůžky"){
        roundResult.innerHTML = "prohra!";
        scorePC += 1;

    }else if (userChoice == "Kámen" && pcChoice == "Papír"){
        roundResult.innerHTML = "prohra!";
        scorePC += 1;

    } else if (userChoice == "Nůžky" && pcChoice == "Papír"){
        roundResult.innerHTML = "výhra!";
        scoreUser += 1;

    } else if (userChoice == "Papír" && pcChoice == "Papír"){
        roundResult.innerHTML = "remíza!";

    } else {
        roundResult.innerHTML = "chyba v kódu. Stěžuj si programátorovi!";
    }

    console.log("Tah uživatel: " + userChoice + ", tah pc: " + pcChoice);

    scoreUserEl.innerHTML = scoreUser;
    scorePCEl.innerHTML = scorePC;

}