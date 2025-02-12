alert("Hello world");

let nom = "ALassane";
const age = 24;
var estEtudiant = true;

console.log(nom, age,estEtudiant);

// les type de donner 
  // chaine de caractere 
     let bonj = "Bonjour" ;
  // Nombre 
     let nombre = 10;
  // boolean 
    let bool = false;
  // Tableau 
     let tab =["pomme","banane","orange"];
     console.log(tab);
  // Object 
     let objet = {
        nom: "ALassane",
        age: 24
     }

     console.log(objet);

     // les conditions (if , else if , else , switch)
      if(age >= 18){
        console.log("vous etes majeur");
      }else{
        console.log("vous etes mineur");
      }

    let jour = "lundi";

        switch (jour) {
            case "lundi":
                console.log("Début de semaine !");
                break;
            case "vendredi":
                console.log("Bientôt le week-end !");
                break;
            default:
                console.log("Jour normal.");
        }

for(let i = 1; i <= 5; i++){
    console.log("Tour n " + i);
}

// premier exercice : cree un script qui demande l'age de l'utilisateur avec prompt(), et affiche un message en fonction de son age (majeur et mineur)

let age2 = parseInt(prompt("Donner votre age"));

if(age2 >= 18){
    console.log("vous etes majeur");
}else{
    console.log("vous etes mineur");
}

for(let i=0;i<=10;i++){
    console.log(i);
}

// les fonction en js

function direBonjour() {
    console.log("Bonjour  !");

}
direBonjour(); // appel de fonction 

// fonction avec 3 parametre 

function saluer(nom,prenom) {
    console.log("Good afternoon " + prenom + " " + nom );
}
saluer("kane","Alassane");

//###fonction flechee 

const multiplication = (x,y) => x*y;
console.log(multiplication(4,2));

///les tableaus en javascript  

let fruits = [
    "Pomme",
    "Banane",
    "Orange"
];
console.log(fruits[0]);

fruits.push("Mangue");// ajouter un mangue a la fin
fruits.pop(); //supprimer le dernier element 
fruits.shift(); //supprimer le premier element
console.log(fruits);
//length de fruits 
console.log(fruits.length);
// `map` transforme chaque élément
let majuscules = fruits.map(fruit => fruit.toUpperCase());
console.log(majuscules);

// `filter` filtre les éléments
let longs = fruits.filter(fruit => fruit.length > 5);
console.log(longs);

// `reduce` cumule les valeurs
let nombres = [1, 2, 3, 4, 5];
let somme = nombres.reduce((total, num) => total + num, 0);
console.log(somme); // Affiche 15


// exercice a faire 

function carre(a){
    return a*a;
}
console.log("carre de 5 est : " + carre(5));


let table = [1,2,3,4,5];

let carres = table.map(carre);
console.log(carres);

function trierPaire(tab){
    let paire = [];
    let nb = tab.length;
    for(let i=0;i<nb;i++){
        if(tab[i]%2 == 0){
            paire.push(tab[i]);
        }
    }
  return paire;
}
console.log(trierPaire(table));

// autre solution pour la fonction trierPaire

const trierPaire1 = (tab1) => tab1.filter(num => num % 2 == 0);
console.log(trierPaire1(carres));

// les objets

let personne = {
    nom: "Alassane",
    Age: 24,
    ville: "Dimath"
}
console.log(personne);

personne.email = "kane@gmail.com";
console.log(personne);

//

let Etudiant = {
    nom1 : "kane",
    prenom1 : "Alassane",
    AGE : 35 ,
    notmoyenne : 12.3,

    afficherInfo: function() {
       console.log(
        `Nom : ${this.nom1},
        Prenom : ${this.prenom1},
        Age : ${this.AGE},
        Moyenne : ${this.notmoyenne}
       `
       )
    }
};

Etudiant.afficherInfo();


let tabEtudiants = [
    { nom: "Kane", prenom: "Alassane", age: 35, noteMoyenne: 12.3 },
    { nom: "Kane", prenom: "Amadou", age: 30, noteMoyenne: 10.3 },
    { nom: "Kane", prenom: "Oumar", age: 32, noteMoyenne: 17.3 }
];

// Trouver le meilleur étudiant




tabEtudiants.forEach(Etudiant=> {
    console.log(Etudiant);
});

function meilleurEtudiants(tabb){
   if(tabb.length === 0) return null;

   let meilleur = tabb[0];

   tabb.forEach(Etudiant => {
      if(Etudiant.noteMoyenne > meilleur.noteMoyenne){
        meilleur = Etudiant;
      }
   });

   return meilleur;
}

let meilleur = meilleurEtudiants(tabEtudiants);

if (meilleur) {
    console.log(`🎓 Meilleur étudiant: ${meilleur.nom} ${meilleur.prenom}, Moyenne: ${meilleur.noteMoyenne}`);
} else {
    console.log("Aucun étudiant trouvé.");
}