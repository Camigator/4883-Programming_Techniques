/************************************
/ 
/ Cameron O'Neal
/ UVA judge 540 Team Queue
/ Programming Techniques
/
*************************************/

#include<iostream>
#include<vector>
#include<set>
// had to do some research on using the set library 
// but very cool stuff

using namespace std;

struct COMEATME{
    int num,L,pos;
    
    COMEATME(int a, int b, int c){
        num=a;
        L=b;
        pos=c;
    }
    
    bool operator < (COMEATME X)const{
        if(L!=X.L) return L<X.L;
        return pos<X.pos;
    }
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    set<COMEATME> team_queue;
    int t,n,a,cont,store=1;
    string command;
    
    vector<int> N(1000000);
    int OtherTeam[1000];
    int team[1000];
    int pos[1000];
    
    set<COMEATME> :: iterator up;
    
    while(cin>>t){
        if(t==0) break;
    
        cout<<"Scenario #"<<store<<endl;
        store++;
    
        for(int i=0;i<t;i++){
            scanf("%d",&n);
            for(int j=0;j<n;j++){
                cin>>a;
                N[a]=i;
            }
        }
        
        fill(team,team+t,0);
        fill(OtherTeam,OtherTeam+t,0);
        
        cont=0;
        
        team_queue.clear();
        
        while(cin>>command){
            if(command[0]=='S')
				break;
            else if(command[0]=='D')
			{
                up=team_queue.begin();
                printf("%d\n",(*up).num);
                OtherTeam[N[(*up).num]]--;
                team_queue.erase(*up);                
            }
			else{
                scanf("%d",&a);
                if(OtherTeam[N[a]]==0){
                    OtherTeam[N[a]]=1;
                    team[N[a]]++;
                    team_queue.insert(COMEATME(a,cont,1));
                    pos[N[a]]=cont;
                    cont++;
                }else{
                    OtherTeam[N[a]]++;
                    team[N[a]]++;
                    team_queue.insert(COMEATME(a,pos[N[a]],team[N[a]]));
                }
            }
        }
        cout<<endl;
    }
    
    return 0;
}