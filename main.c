#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>


int n , m;
int k;//tedad kalantariha
int i1;
int i2;
int j11;
int j2;
int counterdozd=0;
int counterkol=0;


int arr_matrix[10000][10000];

int arr_tedad_policeha_dar_har_kalantari[10000];
int arr_negahdari_jaygah1_police[10000][10000];
int arr_negahdari_jaygah2_police[10000][10000];


void printbokon();
int fasele_oghlidosi();
int harkat_hoshmand_police_ha_dar_kalantari(int satrekalantari);
void manand_dozd_harkat_kardan_police_ha( int satrekalantarii);
int harkat_dozd();
int check_konn(int x, int y);





int millisleep(unsigned ms)
{
    SetLastError(0);
    Sleep(ms);
    return GetLastError() ?-1 :0;
}



void colorme( int vurudi)
{
    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //rangha az 1 shuru mishan ama vurudi mitune -1 ham bashe.
    //-1, 1, 2, 3...
    if(vurudi<0){
        int k=1;
        SetConsoleTextAttribute(hConsole, k);
        printf("    T");
    }
    else{
        int k=vurudi+1;
        SetConsoleTextAttribute(hConsole, k);
        printf("%4dD", vurudi);
    }
    // you can loop k higher to see more color choices
    // for(k = 1; k < 255; k++)
    // {
    SetConsoleTextAttribute(hConsole, 7);
    return ;
}



void printbokon(){
    for (int a=0; a<n; a++){
        for(int b=0; b<m; b++){
            if(arr_matrix[a][b]<0){
                // printf("    T");
                colorme(arr_matrix[a][b]);
            }
            else if(arr_matrix[a][b]==0){
                printf("    -");
            }
            else if(arr_matrix[a][b]>0){
                colorme(arr_matrix[a][b]);
            }
        }
        printf("\n");
    }

    millisleep(1000);
    printf("\n");


    //system("cls");
    return;

}




int harkat_dozd(){
//harkat bady dozd
 i2=(rand()%3)+(i1-1);
 j2=(rand()%3)+(j11-1);
    if(i2>n-1 || j2>m-1 || i2<0 || j2<0){
        while(i2>n-1 || j2>m-1 || i2<0 || j2<0){
        i2=rand()%3+(i1-1);
        j2=rand()%3+(j11-1);

        }
    }
 // agar gayghah dozd avaz shod
    if(i1!=i2 || j11!=j2){
    counterdozd++;
    counterkol++;
    }

    arr_matrix[i1][j11]=0;
    i1=i2;
    j11=j2;
    arr_matrix[i1][j11]=-9;



//agar dozd be khane police beravad
    for(int a=0;a<k;a++){
        for(int b=0;b<arr_tedad_policeha_dar_har_kalantari[a];b++){
            if(i2== arr_negahdari_jaygah1_police[a][b]  && j2==arr_negahdari_jaygah2_police[a][b] ){

            printf("dozd dar in zaman be khane police dar zaman ghabli rafte dar satr:%d va dar soton:%d\n",i2, j2);
            return 1;
            }
        }
    }



    // arr_matrix[i1][j11]=0;
    // i1=i2;
    // j11=j2;
    // arr_matrix[i1][j11]=-9;
     return 2;

}








 int fasele_oghlidosi(){
    bool flag=false;
    for(int i=0 ; i<k ; i++){
        for(int j=0; j<arr_tedad_policeha_dar_har_kalantari[i];j++){
            if(((arr_negahdari_jaygah1_police[i][j] - i1)*(arr_negahdari_jaygah1_police[i][j] - i1))+((arr_negahdari_jaygah2_police[i][j] - j11)*(arr_negahdari_jaygah2_police[i][j] - j11))<=8){
              //seda zadan tabe harkat hoshmand polise ha dar An calantari//
                    int natije=harkat_hoshmand_police_ha_dar_kalantari(i);
                if(natije==1){
                    flag=true;
                    return 1;
                }
                if(natije==2){
                flag=true;
                     i++;
                }


            }
        }

                if (!flag){
                //manand dozd harkat con//
                flag=false;
                manand_dozd_harkat_kardan_police_ha(i);
                }


    }
    return 2;
}







int harkat_hoshmand_police_ha_dar_kalantari(int satrekalantari){
    for(int j=0;j<arr_tedad_policeha_dar_har_kalantari[satrekalantari];j++){
            //agar police samt rast bashad
        if(  arr_negahdari_jaygah2_police[satrekalantari][j] > j11 ){
            ////agar polise samt bala va rast bashad
            if( arr_negahdari_jaygah1_police[satrekalantari][j] <i1 ){
                /// agar khali ya dozd dasht bod khane payin va chap boro
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]-1] ==-9){
                    //khane  ra khali  kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane payin va chap boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]-1]=satrekalantari+1;
                    //agar be khane payin va chap beravad gayghah avalash yek vahed ezafe mishavad
                    // printf("%d\n",arr_negahdari_jaygah1_police[satrekalantari][j]);
                    arr_negahdari_jaygah1_police[satrekalantari][j]++;
                    // printf("%d\n",arr_negahdari_jaygah1_police[satrekalantari][j]);
                    // agar be khane payin va chap beravad gayghah dovomash yek adad kam mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }

                ///agar payin khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane payin boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]=satrekalantari+1;
                    // agar be khane payin beravad gayghah avalash yek adad ezafe mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                        return 1;
                        }
                    continue;
                }

                ////agar chap khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane chap miravad
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]=satrekalantari+1;
                    // agar be khane chap beravad gayghah dovomash yek adad kam mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }


            }

            ///agar samt rast va payin bashad
            if( arr_negahdari_jaygah1_police[satrekalantari][j] > i1 ){
                /// agar khali ya dozd dasht bod khane bala va chap boro
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]-1] ==-9){
                    //khane  ra khali  kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane bala va chap boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]-1]=satrekalantari+1;
                    //agar be khane payin va chap beravad gayghah avalash yek vahed kam mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]--;
                    // agar be khane payin va chap beravad gayghah dovomash yek adad kam mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                    //agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }

                ///agar bala khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane bala boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]=satrekalantari+1;
                    // agar be khane payin beravad gayghah avalash yek adad kam mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }

                ////agar chap khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane chap miravad
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]=satrekalantari+1;
                    // agar be khane chap beravad gayghah dovomash yek adad kam mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                        return 1;
                        }
                    continue;
                }

            }


            ///agar samt rast va hamsatrash bashad
            if(i1==arr_negahdari_jaygah1_police[satrekalantari][j]){
                ///agar samt chap khali ya dozd bod
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]==-9){
                    //khane ra tark kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane chap boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]-1]=satrekalantari+1;
                    // agar be khane chap beravad gayghah dovomash yek adad kam mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }
            }
        }///payan samt rast bodan police

        //agar police samt chap bashad
        if(  arr_negahdari_jaygah2_police[satrekalantari][j] < j11 ){
        ////agar polise samt bala va chap bashad
            if( arr_negahdari_jaygah1_police[satrekalantari][j] < i1 ){
                /// agar khali ya dozd dasht bod khane payin va rast boro
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]+1] ==-9){

                    //khane  ra khali  kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane payin va rast boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]+1]=satrekalantari+1;
                    //agar be khane payin va rast beravad gayghah avalash yek vahed ezafe mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]++;
                    // agar be khane payin va rast beravad gayghah dovomash yek adad ezafe mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }

                ///agar payin khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane payin boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]=satrekalantari+1;
                    // agar be khane payin beravad gayghah avalash yek adad ezafe mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                        return 1;
                        }
                    continue;
                }

                ////agar rast khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane rast miravad
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]=satrekalantari+1;
                    // agar be khane rast beravad gayghah dovomash yek adad ezafe mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }

            }
            ///agar samt chap va payin bashad
            if( arr_negahdari_jaygah1_police[satrekalantari][j] > i1 ){
                /// agar khali ya dozd dasht bod khane bala va rast boro
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]+1] ==-9){
                    //khane  ra khali  kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane bala va rast boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]+1]=satrekalantari+1;
                    //agar be khane bala va rast beravad gayghah avalash yek vahed kam mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]--;
                    // agar be khane bala va rast beravad gayghah dovomash yek adad ezafe mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                        return 1;
                        }
                    continue;
                }

                ///agar bala khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane bala boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]=satrekalantari+1;
                    // agar be khane bala beravad gayghah avalash yek adad kam mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                        return 1;
                        }
                    continue;
                }

                ////agar rast khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==-9){
                    //khane  ra khali kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane rast miravad
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]=satrekalantari+1;
                    // agar be khane rast beravad gayghah dovomash yek adad ezafe mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                    ///agar be khane dozd raft 1 ra return konad
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }


            }


            ///agar samt chap va hamsatr bashad
            if(i1==arr_negahdari_jaygah1_police[satrekalantari][j]){
                ///agar samt rast khali ya dozd bod
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]==-9){
                    //khane ra tark kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane rast boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]+1]=satrekalantari+1;
                    // agar be khane rast beravad gayghah dovomash yek adad ezafe mishavad
                    arr_negahdari_jaygah2_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                        return 1;
                        }
                    continue;
                }
            }
        }


        ///agar Police hamsoton ba dozd bashad
        if(j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
            ///agar Police bala va hamsoton bashad
            if(arr_negahdari_jaygah1_police[satrekalantari][j] < i1){
                ///agar khane payin khali ya dozd bashad
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]==-9){
                    //khane ra tark kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane paien boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]+1][arr_negahdari_jaygah2_police[satrekalantari][j]]=satrekalantari+1;
                    // agar be khane paien beravad gayghah avalash yek adad ezafe mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]++;
                    //agar macan taghir konad
                    counterkol++;
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }


            }
            ///agar Police hamsoton va payin bashad
            if(arr_negahdari_jaygah1_police[satrekalantari][j] > i1){
                //agar khane balaye khali ya Police bod
                if(arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]==0 || arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]==-9){
                    //khane ra tark kon
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]][arr_negahdari_jaygah2_police[satrekalantari][j]]=0;
                    //be khane balaye boro
                    arr_matrix[arr_negahdari_jaygah1_police[satrekalantari][j]-1][arr_negahdari_jaygah2_police[satrekalantari][j]]=satrekalantari+1;
                    // agar be khane balaye beravad gayghah avalash yek adad kam mishavad
                    arr_negahdari_jaygah1_police[satrekalantari][j]--;
                    //agar macan taghir konad
                    counterkol++;
                        if (i1==arr_negahdari_jaygah1_police[satrekalantari][j] && j11==arr_negahdari_jaygah2_police[satrekalantari][j]){
                            return 1;
                        }
                    continue;
                }

            }
        }
    }
 return 2;
} ///payan :)



// x=satr ast
    int check_konn(int x, int y){
        if(x>=n || y>=m||x<0||y<0){
            return 1;
        }
        if(arr_matrix[x][y]!=0){
            return 1;
        }
    return 0;
    }



void manand_dozd_harkat_kardan_police_ha(int satrekalantarii){
    int x_temp, y_temp;
    for(int i=0; i<arr_tedad_policeha_dar_har_kalantari[satrekalantarii]; i++){
        x_temp=rand()%3+arr_negahdari_jaygah1_police[satrekalantarii][i]-1;
        y_temp=rand()%3+arr_negahdari_jaygah2_police[satrekalantarii][i]-1;
        while(check_konn(x_temp, y_temp)==1){
        x_temp=rand()%3+arr_negahdari_jaygah1_police[satrekalantarii][i]-1;
        y_temp=rand()%3+arr_negahdari_jaygah2_police[satrekalantarii][i]-1;
        }
        arr_matrix[arr_negahdari_jaygah1_police[satrekalantarii][i]][arr_negahdari_jaygah2_police[satrekalantarii][i]]=0;
        arr_matrix[x_temp][y_temp]=satrekalantarii+1;
        arr_negahdari_jaygah1_police[satrekalantarii][i]=x_temp;
        arr_negahdari_jaygah2_police[satrekalantarii][i]=y_temp;
    }

    return;

}//payan tabe manand_dozd_harkat_kardan_police_ha




int main()
{
    time_t t= time(NULL);
    srand(t);

    printf("Please enter the number of rows and columns\n");
    scanf("%d %d", &n ,&m);
    /////////
     i1=rand()%(n);
     j11=rand()%(m);
    arr_matrix[i1][j11]=-9;



    printf("please enter number of Police stations\n");
    scanf("%d",&k);

    printf("please enter number of police in each Police stations \n");
    int p;
    for(int a=0;a<k;a++){
    scanf("%d",& p);
    arr_tedad_policeha_dar_har_kalantari[a]=p;
        for(int b=0;b<arr_tedad_policeha_dar_har_kalantari[a];b++){
            int i=rand()%(n);
            int j=rand()%(m);
            if(arr_matrix[i][j]!=0){
                while(arr_matrix[i][j]!=0){
                i=(rand())%(n);
                j=(rand())%(m);
                }

            }
            arr_matrix[i][j]=a+1;


            arr_negahdari_jaygah1_police[a][b]=i;
            // printf("%d\n",arr_negahdari_jaygah1_police[a][b]);

            arr_negahdari_jaygah2_police[a][b]=j;
            // printf("%d\n",arr_negahdari_jaygah2_police[a][b]);
        }
    }
printbokon();






while(2>1){
int res1 = harkat_dozd();
    if(res1==1){
        printbokon();
        break;
    }
    if(res1==2){
        int res2=fasele_oghlidosi();
        if(res2==1){
            printbokon();
            break;
        }
        if(res2==2){
            printbokon();
        }
    }
}

  //printf("\n");
  printf("kol_harkat_ha=%d\n",counterkol);
  printf("kol_harkat_dozd=%d",counterdozd);


 return 0;
}
