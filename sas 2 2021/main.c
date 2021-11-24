#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 // STRUCT POUR  CLIENT =======================================================================================
typedef struct client
   {
       char nom [30];
       char prenom [20];
       int  numero,i ;
       char  CIN [8];
       float montant;

   }client;
   int count_c=0;
    client c[20];


   void trie_Ascendant( ) {

//float montant ;
       int i, j, pos ;
       client cl;
   float min;
    for(i=0;i<count_c;i++)
    {
          
         for (j=i+1;j<count_c;j++)
         {
          if(c[i].montant>c[j].montant)
          {
           cl = c[i];
           c[i]=c[j];
           c[i]=cl;
           }
         }
          
    }
    for(i=0;i<count_c;i++){

    printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
}
	}
void trie_Descendant( ) {
    
float montant ;
 float min;
int i, j, pos;
    for(i=0;i<count_c;i++)
    {
          min=c[i].montant;
         for (j=i+1;j<count_c;j++)
         {
          if(c[j].montant>min)
          {
           min=c[j].montant;
           pos=j;
           }
         }
          c[i]=c[i];
          c[i] =c[pos] ;
          c[pos]=c[i];
    }
    printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
}
void fidelisation()
{
    int i;
	trie_Descendant( );
	for(i=0;i<3;i++)
	{
		c[i].montant+=c[i].montant*0.013;
		 printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
	}
}



int main()
{
    // LES VARIABLE ===========================================================================================
                    struct client c[100];
                    int choix,choix1,choix2,i , nbr=0,count_c=0,retrait =0,depot=0,found;
                    char recherche [50];
                    c[i].montant =0;
        do
        {
            do
            {
             // menu prinsipale ==============================================================================
                printf("=========================== Menu =============================\n");

                printf("1 => cree un compte bancaire \n");
                printf("2 => plusieurs comptes bancaires\n");
                printf("3 => Operations \n");
                printf("4 => Affichage\n");
                printf("5 => Fidelisation\n");
                printf("6 => Quitter l'application \n\n");

                printf("Votre choix : ");
		    	scanf("%d", &choix);




            }while(choix <1 || choix>6);

          switch(choix)
          {

                case 1: // entrer un compte ===========================================================================
                         printf("\n entrer le nom client : \n");
                         scanf("%s",c[count_c].nom);
                         printf("\n entrer le prenom client : \n");
                         scanf("%s",c[count_c].prenom);
                         printf("entrer le numero client : \n");
                         scanf("%d",c[count_c].numero);
                         printf("entrer le montant \n");
                         scanf("%f",&c[count_c].montant);
                         printf("entrer le CIN client :\n ");
                         scanf("%s",c[count_c].CIN);
                            count_c++;

                            system("cls");




                    break;

                case 2: // enter plusieur compte ======================================================================
                         printf("entrer le nombre des compte :\n");
                         scanf("%d",&nbr);

                        for(i=count_c ; i<nbr+count_c ; i++)
                        {


                            printf("----|| client [%d] ||----\n\n",i+1);
                            printf("entrer le nom de client [%d]= : ",i+1);
                            scanf("%s",c[i].nom);
                            printf("entrer le prenom de client [%d]= : ",i+1);
                            scanf("%s",c[i].prenom);
							printf("entrer le numero de client : ");
                            scanf("%d",&c[i].numero);
                            printf("entrer le montant de client : ");
                            scanf("%f",&c[i].montant);

                            printf("entrer le CIN de client : ");
                            scanf("%s",c[i].CIN);


                            printf("\n\n ");


                        }
                                count_c = count_c+nbr;

                    break;

                case 3: // enter les operation ==============================================================================
                     printf("Operations \n");

                    int choix1;
                        do
                        {
                            printf("1 => retrait\n");
                            printf("2 => depot \n");

                            printf("entrez votre choix : ");
                            scanf("%d", &choix1);

                        }while(choix1 <1 || choix1>2);
                          switch(choix1)
                            {
                                case 1: // retrait ==========================================================================

                                     printf("Entrer cin qui veut cette opération: ");
                                       scanf("%s", recherche);

                                       for(i=0; i<count_c; i++)
                                       {

                                         if(strcmp(recherche,c[i].CIN )== 0)
                                         {
                                           found=1;
                                           printf("%d le nom %s \t le prenom %s \t le numero %s \t  CIN %s \t le mantant %f DH \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);


                                         }



                                        printf("entrer la somme de retrait en DH : \n");
                                        scanf("%d", &retrait);
                                        do
                                        {
                                            if(retrait<100 ) // CONDITION POUR LE MANTANT SUPERIEUR A 100
                                                {
                                                printf("entrer la somme de retrait en DH superieur a  100 : \n");
                                                scanf("%d", &retrait);
                                                }

                                        }while (retrait<100);
                                        if (retrait>c[0].montant) // POUR NE PAS RETRAIT A COMPTE IF MANTANT EGALE 0

                                            printf(" Votre Montant ne pa Suffisant pour retirer \n");

                                        else

                                            c[0].montant= c[0].montant-retrait;
                                            printf("le montant apres le retrait est %f",c[0].montant);
                                        }

                                        if(found==0) printf("Not found");


                               break;

                            case 2: //  DEPOT  =====================================================================================

                                        printf("Entrer cin qui veut cette opération: ");
                                       scanf("%s", recherche);

                                       for(i=0; i<count_c; i++)
                                       {

                                         if(strcmp(recherche, c[i].CIN )== 0)
                                         {
                                           found=1;
                                           printf("[%d] le nom [%s] \t le prenom [%s] \t  le numero [%s] \t  CIN [%s] \t le montant [%d] \n\n "
                                                   ,i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
                                         }

                                         printf("entrer la somme de depot en DH : \n");
                                        scanf("%d", &depot);
                                          do
                                        {

                                            if(depot<100){ // CONDITION POUR LE MANTANT SUPERIEUR A 0
                                                printf("entrer la somme de depot en DH superieur a # 100#: \n");
                                                scanf("%d", &depot);
                                            }

                                        }while (depot<100);

                                        c[0].montant= c[0].montant+depot;
                                        printf("le montant apres le depot est %f",c[0].montant);
                                       }

                                        if(found==0) printf("Not found");

                                                break;

                                                default:
                                                 break;
                                                }

                                           break;



                     case 4: // AFFICHAGE ==================================================================================

				printf("1 => recherche par cin \n");
                printf("2 => Par Ordre Ascendant\n");
                printf("3 => Par Ordre Descendant \n");
                printf("4 => Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit )\n ");
                printf("5 => Par Ordre Descendant (les comptes bancaire ayant un montant supérieur à chiffre introduit) \n");
                printf("6 => afficher la liste des donnees \n");

                printf("Votre choix : ");
			scanf("%d", &choix2);

            while(choix2 <1 || choix2>5);
            switch(choix2)
			{
            	case 1: printf("Enter a CIN  to search: ");
                       scanf("%s", recherche);

                       for(i=0; i<count_c; i++)
                       {

                         if(strcmp(recherche, c[i].CIN )== 0)
                         {
                           found=1;
                           printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le montant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
                         }
                       }

                        if(found==0) printf("Not found");
                        break;
                case 2:
                	trie_Ascendant();
                	break;
                case 3:
                	trie_Descendant();
                	break;
                	float m;
                case 4:
                	
                	printf("entrez le montant");
                	scanf("%f",&m);
                	if(m<c[i].montant){

//                	trie_Ascendant();
                	printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le montant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
                		}
                	else
                	printf("Error");
                	break;
                case 5:
                printf("entrez le montant");
                	scanf("%f",&m);
                	if(m<c[i].montant){

                		trie_Descendant();
                		printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le montant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
                		}
                	else
                	printf("Error");


                         for(i=0 ; i<count_c ; i++)
                         {

                            printf("[%d] le nom [%s] \t le prenom [%s] \t le numero [%s] \t  CIN [%s] \t le montant [%d] \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
                         }

                	break;

                                default:
                                    break;

			}
			case 5: printf("fidelisation \n");
		      	fidelisation();
		      	printf("les montant apres fidelisatin est %f",c[i].montant);
			break;
			case 6: printf(" ");
            break;
                default:
                    break;
        }

                        }while(choix !=6);
                    return 0;
                    system("pause");
    }
