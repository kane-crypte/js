//Question du quiz

const questions = [
    {
        question: "Quelle est la capitale du Senegale",
        answers:["Dakar","Saint louis","Matam","kolda"],
        correct: 0
    },
    {
        question:"Qui le president du senegal",
        answers:["Bassir faye","Macky sall","Abdoulaye wade"],
        correct: 0
    }
];

let currentQuestion = 0; //inde de la question actuelle 
let score = 0; //score de l'utilisateur

const questionElement = document.getElementById("question");
const answersElement = document.getElementById("answers");
const scoreElement = document.getElementById("score");

function showQuestion() {

    const question = questions[currentQuestion];

    questionElement.textContent = question.question;

    answersElement.innerHTML = "";

    question.answers.forEach((answers,index) => {
        const button = document.createElement("button");
        button.textContent = answers;
        button.onclick = () => checkAnswer(index);
        answersElement.appendChild(button);
        
    });
}
    //verification si la repnse est correct 

    function checkAnswer(selectedIndex){
        const question = questions[currentQuestion];

        if(selectedIndex === question.correct){
            score++;
            alert("Bonne reponse");
        }else{
            alert("Mauvais reponse etat :" + question.answers[question.correct]);

        }
        currentQuestion++;

        if(currentQuestion >= questions.length){
            showScore();
        }else{
            showQuestion();
        }
    }


    function showScore(){
        questionElement.textContent = "Quiz termine";
        answersElement.innerHTML = "";
        scoreElement.textContent = "Votre score: " + score + " / "+ questions.length;
    }

    showQuestion();
