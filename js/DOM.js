let titre = document.getElementById("titre");
console.log(titre.innerHTML);

let texte = document.getElementsByClassName("texte");
console.log(texte[0].innerHTML);

let titres = document.getElementsByTagName("h1");
console.log(titres[0].innerHTML);

let premierParagraphe = document.querySelector(".texte"); // Premier élément trouvé
console.log(premierParagraphe);

let tousLesParagraphes = document.querySelectorAll(".texte"); // Liste de tous les éléments
console.log(tousLesParagraphes);

//  modification de titre 

titre.innerHTML = "DOM modifie !";

titre.innerHTML = "<em>Nouveau texte</em>";

// modification les style css

titre.style.color = "red";
titre.style.fontSize = "30px";


// ajouter ou supprimer 

let nouveauParagraphe = document.createElement("p");
nouveauParagraphe.innerHTML = "Je suis un nouveau paragraphe";
document.body.appendChild(nouveauParagraphe);

document.body.insertBefore(nouveauParagraphe,titre);


//titre.remove();

let bouton = document.getElementById("monBouton");
bouton.addEventListener("click", function() {
    alert("Bouton cliqué !");
});


window.addEventListener("load",function(){console.log("Page charge !");});