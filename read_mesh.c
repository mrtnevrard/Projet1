#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <string.h>


int main(){

  FILE* fichier1;
  char ligne1[256];
  int i,n_nodes,nothing,n_elements,**element,n_tag,*type_of,j,test1;
  double** node;
  double a,b,c;


  test1=0;


  //-------------------ouverture du fichier .msh---------------------------------

  
  fichier1=fopen("cube.msh","r");


  //-------------------------lignes inintéressantes------------------------------
  
  for(i=1 ; i<7 ; i++){
    fscanf(fichier1,"%s \n",ligne1);
  }



  //---------------------allocations du nombre de noauds-----------------------
  fscanf(fichier1,"%d \n",&n_nodes);
  node = (double**)calloc( n_nodes , sizeof(double*));
  
  
  for( i = 0 ; i < n_nodes ; i++ ){
      node[i] = (double*) calloc (3, sizeof(double));
    }
  
  for(i=0 ; i<n_nodes ; i++){
   
    fscanf(fichier1,"%d %lf %lf %lf \n",&nothing,& node[i][0],&node[i][1],&node[i][2]);
   
  }



  //------------------éléments inintéressants---------------------------
  
  fscanf(fichier1,"%s \n",ligne1);
  fscanf(fichier1,"%s \n",ligne1);

  //-----------------nombre d'éléments----------------------------
  fscanf(fichier1,"%d \n",&n_elements);
  element = (int**)calloc( n_elements , sizeof(int*));
  type_of = (int*)calloc( n_elements,sizeof(int));




  
  for( i = 0 ; i < n_elements ; i++ )
    {
 
      fscanf(fichier1,"%d %d %d",&nothing,&type_of[i],&n_tag);
      printf("ok %d\n",nothing);

      if(((type_of[i]+1)<=4) && ((type_of[i]+1)>=3)){
	test1++;


      for ( j=0 ; j<n_tag ; j++ ){
	
	fscanf(fichier1,"%d",&nothing);
      }
      
      element[i] = (int*) calloc (type_of[i]+1, sizeof(int));



      
      for( j=0 ; j<=type_of[i] ; j++ ){
       
	if(j!=type_of[i]){
	
	fscanf(fichier1,"%d",&element[i][j]);

	}

	else{

	  fscanf(fichier1,"%d\n",&element[i][j]);
	  
	}
	
	
      }


      }
       else{



      for ( j=0 ; j<n_tag ; j++ ){
	
	fscanf(fichier1,"%d",&nothing);
      }
      
      element[i] = (int*) calloc (type_of[i]+1, sizeof(int));



      
      for( j=0 ; j<=type_of[i] ; j++ ){
       
	if(j!=type_of[i]){
	
	fscanf(fichier1,"%d",&nothing);

	}

	else{

	  fscanf(fichier1,"%d\n",&nothing);
	  
	}
	
	
      }

     
      }
    }
  fclose(fichier1);

  printf("nombre d'elements = %d \n",n_elements);
    printf("test1 = %d \n",test1);
}
