#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Structures de donnees*/

typedef struct Voyageur { 
	int id;
	int idStationDepart;
	int idStationArrivee;
}Voyageur;

typedef struct VoyageurElement{
	Voyageur v;
	VoyageurElement* next;
}VoyageurElement;

typedef struct ListeVoyageur{
	VoyageurElement* first;
}ListeVoyageur;

typedef struct Station{
	int id;
	int x;
	int y;
	int capacite;
	ListeVoyageur* voyageurs;
}Station;

typedef struct StationElement{
	Station s;
	ListeStation* next;
}StationElement;

typedef struct ListeStation{
	StationElement* first;
}ListeStation;

typedef struct Bus {
	int id;
	int x;
	int y;
	int station;
	int nbVoiture;
	ListeVoyageur* voyageurs;
}Bus;

typedef struct Joueur {
	int id;
	int banque;
	int ameliorationVoiture;
	int ameliorationVitesse;
	int ameliorationTarif;
	Bus bus[4];
}Joueur;

/*fonctions*/

void initialiserPartie(struct Joueur** joueurs, int nbJoueur){

	int i;

	*joueurs = (struct Joueur*)malloc(nbJoueur*sizeof(struct Joueur));
	for(i=0; i < nbJoueur ; i++){

		*joueurs[i] = (struct Joueur){.id=i,.banque=150,.ameliorationVoiture=0,.ameliorationVitesse=0,.ameliorationTarif=0,.bus={}};

	}

}

void ajouterStation(struct ListeStation* liste, struct Station s){

	struct StationElement* nouvelleStation,* stationCourante;
	nouvelleStation = (struct StationElement*)malloc(sizeof(struct StationElement));
	nouvelleStation->s = s;
	stationCourante = liste->first;

	while(stationCourante->next!=NULL){
		stationCourante = stationCourante->next;	
	}

	stationCourante->next = nouvelleStation;

}

void* chercherStationParId(int id,struct ListeStation* liste){

	struct StationElement* stationCourante;
	stationCourante = liste->first;

	while(stationCourante!=NULL){
		if(stationCourante->s.id==id){
			return &stationCourante->s;
		}
		stationCourante = stationCourante->next;	
	}

	return NULL;

}

void ajouterVoyageur(struct ListeVoyageur* liste, struct Voyageur v){

	struct VoyageurElement* voyageurCourant,* nouveauVoyageur;
	nouveauVoyageur = (struct VoyageurElement*) malloc(sizeof(struct VoyageurElement));
	nouveauVoyageur->v = v;
	voyageurCourant = liste->first;

	while(voyageurCourant->next!=NULL){
		voyageurCourant = voyageurCourant->next;	
	}

	voyageurCourant->next = nouveauVoyageur;

}

struct Voyageur* chercherVoyageurParId(int id,struct ListeVoyageur* liste){

	struct VoyageurElement* voyageurCourant;
	voyageurCourant = liste->first;

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
