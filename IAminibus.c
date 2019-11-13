#include <stdio.h>
#include <stdlib.h>

/*Structures de donnees*/

struct Station{
	int id,
	int x,
	int y,
	int capacite,
	struct ListeVoyageur voyageurs
};

struct ListeStation{
	struct Station s,
	struct ListeStation* next
};

struct ListeVoyageur{
	struct Voyageur v,
	struct ListeVoyageur* next
};

struct Voyageur { 
	int id,
	int idStationDepart,
	int idStationArrivee
};

struct Bus {
	int id,
	int x,
	int y,
	int station,
	int nbVoiture,
	struct Voyageur* voyageurs
};

struct Joueur {
	int id,
	int banque,
	int ameliorationVoiture,
	int ameliorationVitesse,
	int ameliorationTarif,
	struct Bus bus[4]
};

/*fonctions*/

void initialiserPartie(struct Joueur** joueurs, int nbJoueur){

	int i;

	*joueurs = (struct Joueur*)malloc(i*sizeof(struct Joueur));
	for(i=0; i < nbJoueur ; i++){

		*joueurs[i] = {i,150,0,0,0,{}};

	}

}

void ajouterStation(struct ListeStation* liste, struct Station s){

	struct ListeStation nouvelleStation, stationCourante;
	nouvelleStation.s = s;
	stationCourante = *liste;

	while(stationCourante.next!=NULL){
		stationCourante = stationCourante.next;	
	}

	stationCourante.next = nouvelleStation;

}

struct Station chercherStationParId(int id,struct ListeStation liste){

	struct ListeStation stationCourante;
	stationCourante = liste;

	while(stationCourante.next!=NULL){
		if(stationCourante.s.id==id){
			return stationCourante.s;
		}
		stationCourante = stationCourante.next;	
	}

	return NULL;

}

void ajouterVoyageur(struct ListeVoyageur* liste, struct Voyageur v){

	struct ListeVoyageur nouveauVoyageur, voyageurCourant;
	nouveauVoyageur.v = v;
	voyageurCourant = *liste;

	while(voyageurCourant.next!=NULL){
		voyageurCourant = voyageurCourant.next;	
	}

	voyageurCourant.next = nouveauVoyageur;

}

struct Voyageur chercherStationParId(int id,struct ListeVoyageur liste){

	struct ListeVoyageur voyageurCourant;
	voyageurCourant = liste;

	while(voyageurCourant.next!=NULL){
		if(voyageurCourant.v.id==id){
			return voyageurCourant.v;
		}
		voyageurCourant = voyageurCourant.next;	
	}

	return NULL;

}

/*main*/

int main(int argc,char ** argv){

	struct Joueur* joueur;
	int nbJoueur;

	nbJoueur = 5;
	initialiserPartie(&joueur,nbJoueur);

}		
