#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Structures de donnees*/

struct Voyageur { 
	int id;
	int idStationDepart;
	int idStationArrivee;
};

struct ListeVoyageur{
	struct Voyageur v;
	struct ListeVoyageur* next;
};

struct Station{
	int id;
	int x;
	int y;
	int capacite;
	struct ListeVoyageur voyageurs;
};

struct ListeStation{
	struct Station s;
	struct ListeStation* next;
};

struct Bus {
	int id;
	int x;
	int y;
	int station;
	int nbVoiture;
	struct Voyageur* voyageurs;
};

struct Joueur {
	int id;
	int banque;
	int ameliorationVoiture;
	int ameliorationVitesse;
	int ameliorationTarif;
	struct Bus bus[4];
};

/*fonctions*/

void initialiserPartie(struct Joueur** joueurs, int nbJoueur){

	int i;

	*joueurs = (struct Joueur*)malloc(nbJoueur*sizeof(struct Joueur));
	for(i=0; i < nbJoueur ; i++){

		*joueurs[i] = (struct Joueur){.id=i,.banque=150,.ameliorationVoiture=0,.ameliorationVitesse=0,.ameliorationTarif=0,.bus={}};

	}

}

void ajouterStation(struct ListeStation* liste, struct Station s){

	struct ListeStation* nouvelleStation,* stationCourante;
	nouvelleStation = (struct ListeStation*)malloc(sizeof(struct ListeStation));
	nouvelleStation->s = s;
	stationCourante = liste;

	while(stationCourante->next!=NULL){
		stationCourante = stationCourante->next;	
	}

	stationCourante->next = nouvelleStation;

}

void* chercherStationParId(int id,struct ListeStation* liste){

	struct ListeStation* stationCourante;
	stationCourante = liste;

	while(stationCourante!=NULL){
		if(stationCourante->s.id==id){
			return &stationCourante->s;
		}
		stationCourante = stationCourante->next;	
	}

	return NULL;

}

void ajouterVoyageur(struct ListeVoyageur* liste, struct Voyageur v){

	struct ListeVoyageur* voyageurCourant,* nouveauVoyageur;
	nouveauVoyageur = (struct ListeVoyageur*) malloc(sizeof(struct ListeVoyageur));
	nouveauVoyageur->v = v;
	voyageurCourant = liste;

	while(voyageurCourant->next!=NULL){
		voyageurCourant = voyageurCourant->next;	
	}

	liste->next = nouveauVoyageur;

}

struct Voyageur* chercherVoyageurParId(int id,struct ListeVoyageur* liste){

	struct ListeVoyageur* voyageurCourant;
	voyageurCourant = liste;

	while(voyageurCourant!=NULL){
		if(voyageurCourant->v.id==id){
			return &(voyageurCourant->v);
		}
		voyageurCourant = voyageurCourant->next;	
	}

	return NULL;

}

/*main*/

int main(int argc,char ** argv){

	struct Joueur* joueurs;
	int nbJoueur;
	int moi;

	fscanf(stdin,"%d %d",&nbJoueur,&moi);

	initialiserPartie(&joueurs,nbJoueur);

	while(1){

		write(1,"PASS\n",5);

	}

}		
