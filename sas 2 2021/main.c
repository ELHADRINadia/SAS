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

   }
   client;
   int count_c=0;
    client c[20];
    int i,j; 

   // void Affichage() {
   //     int i;
   //  for(i=1;i<=count_c;i++)
    //{
    // printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
    //}

  // }





 void trie_Ascendant()
{
    
    char tempCIN[10], tempNom[20], tempPrenom[20];
    float tempMontant;
    for(i=0;i<count_c-1;i++)
    {
        for(j=i+1;j<=count_c-1-i;j++)
        {
            if(c[j].montant<c[i].montant)
            {
                strcpy(tempCIN,c[i].CIN);
                strcpy(c[i].CIN,c[j].CIN);
                strcpy(c[j].CIN,tempCIN);

                strcpy(tempNom,c[i].nom);
                strcpy(c[i].nom,c[j].nom);
                strcpy(c[j].nom,tempNom);

                strcpy(tempPrenom,c[i].prenom);
                strcpy(c[i].prenom,c[j].prenom);
                strcpy(c[j].prenom,tempPrenom);

                tempMontant=c[i].montant;
                c[i].montant=c[j].montant;
                c[j].montant=tempMontant;
            }
        }
    }
}

   void trie_Descendant()
{
    char tempCIN[10], tempNom[20], tempPrenom[20];
    float tempMontant;
    for(i=1;i<count_c;i++)
	

        for(j=i+1;j<=count_c;j++)
        {
            if(c[j].montant>c[i].montant)
            {
                //permutation
                strcpy(tempCIN,c[i].CIN);
                strcpy(c[i].CIN,c[j].CIN);
                strcpy(c[j].CIN,tempCIN);

                strcpy(tempNom,c[i].nom);
                strcpy(c[i].nom,c[j].nom);
                strcpy(c[j].nom,tempNom);

                strcpy(tempPrenom,c[i].prenom);
                strcpy(c[i].prenom,c[j].prenom);
                strcpy(c[j].prenom,tempPrenom);

                tempMontant=c[i].montant;
                c[i].montant=c[j].montant;
                c[j].montant=tempMontant;
            }
        }
    }

int main()
{
    // LES VARIABLE ===========================================================================================
                    struct client c[100];
                    int choix,choix1,choix2,i , nbr=0,count_c=0,retrait =0,depot=0,found;
                    char recherche [50];
                    float m;
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
                case 1:
                     {// entrer un compte ===========================================================================

                        printf("----|| client [%d] ||----\n",count_c+1);

                        printf(" entrer le nom client : ");
                         scanf("%s",c[count_c].nom);
                         printf(" entrer le prenom client : ");
                         scanf("%s",c[count_c].prenom);
                         printf(" entrer le numero client : ");
                         scanf("%d",&c[count_c].numero);
                         printf("entrer le montant \n");
                         scanf("%f",&c[count_c].montant);
                         printf("entrer le CIN client :  ");
                         scanf("%s",c[count_c].CIN);
                            count_c++;

                            system("cls");

                    break;}

                case 2:
                     {// enter plusieur compte ======================================================================
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

                    break;}

                case 3:
                    {// enter les operation ==============================================================================
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
                                case 1:
                                    {// retrait ==========================================================================

                                     printf("Entrer cin qui veut cette opération: ");
                                       scanf("%s", recherche);

                                       for(i=0; i<count_c-1; i++)
                                       {

                                         if(strcmp(recherche,c[i].CIN )== 0)
                                         {
                                           found=1;
  printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %f DH \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
	
									do
                                        {
                                        printf("entrer la somme de retrait en DH : \n");
                                        scanf("%d", &retrait);
                                        
                                            if(retrait<100 ) // CONDITION POUR LE MONTANT SUPERIEUR A 100
                                                
                                                printf("entrer la somme de retrait en DH superieur a  100 : \n");
                                              

                                        }while (retrait<100);
                                        if (retrait>c[i].montant) // POUR NE PAS RETRAIT A COMPTE IF MONTANT EGALE 0

                                            printf(" Votre Montant ne pa Suffisant pour retirer \n");

                                        else{
										

                                            c[i].montant= c[i].montant-retrait;
                                            printf("le montant apres le retrait est %f\n",c[i].montant);
                                        }
												}

                                         }
				 


                                        if(found==0) printf("Not found");


                               break;}

                                case 2:
                                    {//  DEPOT  =====================================================================================

                                        printf("Entrer cin qui veut cette opération: ");
                                       scanf("%s", recherche);

                                       for(i=0; i<count_c-1; i++)
                                       {

                                         if(strcmp(recherche, c[i].CIN )== 0)
                                         {
                                           found=1;
                                           printf("[%d] le nom [%s] \t le prenom [%s] \t  le numero [%s] \t  CIN [%s] \t le montant [%d] \n\n "
                                                   ,i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
                                       

                                         
                                          do
                                        {
                                        	printf("entrer la somme de depot en DH : \n");
                                        scanf("%d", &depot);

                                            if(depot<100){ // CONDITION POUR LE MANTANT SUPERIEUR A 0
                                                printf("entrer la somme de depot en DH superieur a # 100#: \n");
                                                scanf("%d", &depot);
                                            }

                                        }while (depot<100);

                                        c[i].montant= c[i].montant+depot;
                                        printf("le montant apres le depot est %f",c[i].montant);
                                       }
                                   }

                                        if(found==0) printf("Not found");

                                                break;}

                                                default:
                                                 break;
                                                }

                            break;}

                case 4:
                         {// AFFICHAGE ==================================================================================
        		do{

				printf("1 => recherche par cin \n");
                printf("2 => Par Ordre Ascendant\n");
                printf("3 => Par Ordre Descendant \n");
                printf("4 => Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit )\n ");
                printf("5 => Par Ordre Descendant (les comptes bancaire ayant un montant supérieur à chiffre introduit) \n");
                printf("6 => afficher la liste des donnees \n");

             printf("Votre choix : ");
			scanf("%d", &choix2);

            }while(choix2 <1 || choix2>5);
            switch(choix2)
			{
            	case 1:
            	    {printf("Enter a CIN  to search: ");
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
                        break;}
                case 2:
                	{
                	trie_Ascendant();
                     for(i=0;i<=count_c-1;i++)
                    printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
               	break;}
                case 3:
                	{
                	    trie_Ascendant();
              for(i=count_c-1;i>=0;i--)
    {
     printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %.2f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
    }
                	break;}
                case 4:
                    {
                	printf("entrez le montant");
                	scanf("%f",&m);
              			trie_Ascendant();
                	 for(i=0;i<=count_c-1;i++)
    {				if(m<c[i].montant)
     printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %.2f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
    }
                		
                	break;}
                case 5:
                    {
                printf("entrez le montant");
                	scanf("%f",&m);
                	trie_Ascendant();
                	        	
                	 for(i=count_c-1;i>=0;i--)
   					 {			if(m<c[i].montant)
     			printf("%d le nom %s \t le prenom %s \t le numero %d \t  CIN %s \t le mantant %.2f \n\n ",i+1,c[i].nom,c[i].prenom,c[i].numero,c[i].CIN,c[i].montant);
    				}
                	break;}

                 default:
               break;

			}
                  break;  }
                  

                case 5:
                    {
			     printf("fidelisation \n");
		      if(count_c<3){
      for( i=1;i<=count_c;i++){
      printf("\n- nous allons ajouter 1.3 to %s  : %.2f",c[i].CIN,c[i].montant);
      printf("\n");
      c[i].montant += c[i].montant*0.013;
      printf("\n maintenant il a  %.2f ",c[i].montant);
       printf("\n");
      }
     }
     else{
     trie_Descendant();
     for( i =1;i<=3;i++){
     printf("\n nous allons ajouter 1.3 to %s  : %.2f",c[i].CIN,c[i].montant);
      printf("\n");
      c[i].montant += c[i].montant*0.013;
      printf("\n maintenant il a %.2f ",c[i].montant);
      printf("\n");
     }
     }
                break;}
                case 6:
                    {
			         printf("");
            break;}
          default:
            break;}
             }while(choix !=6);
			 return 0;
                        }
                    
                    
        
  
     
    
    
