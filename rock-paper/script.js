const scoreUserEl = document.getElementById("score-player");
const scorePCEl = document.getElementById("score-pc");
const roundResultEl = document.getElementById("roundResult");
const pcChoiceRandom = document.getElementById("pc-choice-button");
const pcChoiceRandomIncentive = document.getElementsByClassName("choice-button");



const choices = ["Kámen", "Nůžky", "Papír"];
const choices1 = {
    "Kámen":"✊",
    "Nůžky":"✌", 
    "Papír":"🖐"}



let userChoice = "";
let pcChoice = "";
let scorePC = 0;
let scoreUser = 0;


const pausecomp = (millis) =>
{
    var date = new Date();
    var curDate = null;
    do { curDate = new Date(); }
    while(curDate-date < millis);
}




const validateChoice = (btnId) =>{
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

    let pcChoice = choices[Math.floor(Math.random() * choices.length)];
    pcChoiceRandom.firstChild.nodeValue = choices1[pcChoice];


    console.log(userChoice, pcChoice)

    if (userChoice === "Kámen" && pcChoice === "Kámen"){
        roundResultEl.firstChild.nodeValue = "remíza!";

    } else if (userChoice === "Nůžky" && pcChoice === "Kámen"){
        roundResultEl.firstChild.nodeValue = "prohra!";
        scorePC += 1;
    } else if (userChoice === "Papír" && pcChoice === "Kámen"){
        roundResultEl.firstChild.nodeValue = "výhra!";
        scoreUser += 1;

    } else if(userChoice === "Kámen" && pcChoice === "Nůžky"){
        roundResultEl.firstChild.nodeValue = "výhra!";
        scoreUser += 1;

    } else if (userChoice === "Nůžky" && pcChoice === "Nůžky"){
        roundResultEl.firstChild.nodeValue = "remíza!";

    } else if (userChoice === "Papír" && pcChoice === "Nůžky"){
        roundResultEl.firstChild.nodeValue = "prohra!";
        scorePC += 1;

    } else if (userChoice === "Kámen" && pcChoice === "Papír"){
        roundResultEl.firstChild.nodeValue = "prohra!";
        scorePC += 1;

    } else if (userChoice === "Nůžky" && pcChoice === "Papír"){
        roundResultEl.firstChild.nodeValue = "výhra!";
        scoreUser += 1;

    } else if (userChoice === "Papír" && pcChoice === "Papír"){
        roundResultEl.firstChild.nodeValue = "remíza!";

    } else {
        roundResultEl.firstChild.nodeValue = "chyba v kódu. Stěžuj si programátorovi!";
    }

    console.log("Tah uživatel: " + userChoice + ", tah pc: " + pcChoice);

    scoreUserEl.firstChild.nodeValue = scoreUser;
    scorePCEl.firstChild.nodeValue = scorePC;

}