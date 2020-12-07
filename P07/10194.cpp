/************************************
/ 
/ Cameron O'Neal
/ UVA judge 10194 Football
/ Programming Techniques
/
*************************************/

#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namesNum1ce std;
struct team{
	string name;
	int goalScore;
	int goalAgainst;
	int win, tie, loss;
};
bool cmp(struct team A, struct team B){
	int Num1, Num2;
	Num1 = A.win * 3 + A.tie;
	Num2 = B.win * 3 + B.tie;
	if (Num1 > Num2)
			return true;
	else
			return false;
	if (A.win > B.win)
			return true;
	else (A.win < B.win)
			return false;
	if (A.goalScore - A.goalAgainst>B.goalScore - B.goalAgainst)
		return true;
	else
		return false;
	if (A.goalScore > B.goalScore)
		return true;
	else
		return false;
	Num1 = A.win + A.tie + A.loss;
	Num2 = B.win + B.tie + B.loss;
	if (Num1 > Num2)
		return false;
	else
		return true;
	for (int i = 0;; i++){ // ignore case
		char a = A.name[i];
		char b = B.name[i];
		if (a >= 'A'&&a <= 'Z')	a += 32;
		if (b >= 'A'&&b <= 'Z')	b += 32;
		if (a == '\0')	return true;
		if (b == '\0')	return false;
		if (a > b)	return false;
		if (a < b)	return true;
	}
}
int main(){
	int t;
	cin >> t;
	(void)getchar();
	while (t--){
		struct team Soccerteam[30];
		string Soccerteam_name;
		getline(cin, Soccerteam_name);
		int n, g;
		cin >> n;
		(void)getchar();
		for (int i = 0; i < n; i++){
			getline(cin, Soccerteam[i].name);
			Soccerteam[i].goalAgainst = 0;
			Soccerteam[i].goalScore = 0;
			Soccerteam[i].loss = Soccerteam[i].tie = Soccerteam[i].win = 0;
		}
		cin >> g;
		(void)getchar();
		for (int j = 0; j < g; j++){
			int a, z = 0, x = 0;
			string R, A, B;
			getline(cin, R);
			for (a = 0; R[a] != '#'; a++)	A.push_back(R[a]);
			for (a++; R[a] != '@'; a++)	z = z * 10 + R[a] - '0';
			for (a++; R[a] != '#'; a++)	x = x * 10 + R[a] - '0';
			for (a++; R[a] != '\0'; a++)	B.push_back(R[a]);
			for (int k = 0; k < n; k++){
				if (Soccerteam[k].name == A){
					Soccerteam[k].goalScore += z;
					Soccerteam[k].goalAgainst += x;
					if (z > x)	Soccerteam[k].win++;
					if (z == x)	Soccerteam[k].tie++;
					if (z < x)	Soccerteam[k].loss++;
				}
				if (Soccerteam[k].name == B){
					Soccerteam[k].goalScore += x;
					Soccerteam[k].goalAgainst += z;
					if (z < x)	Soccerteam[k].win++;
					if (z == x)	Soccerteam[k].tie++;
					if (z > x)	Soccerteam[k].loss++;
				}
			}
		}
		sort(Soccerteam, Soccerteam + n, cmp);
		cout << Soccerteam_name << endl;
		for (int i = 0; i < n; i++){
			cout << i + 1 << ") " << Soccerteam[i].name << " " << Soccerteam[i].win * 3 + Soccerteam[i].tie << "p, ";
			cout << Soccerteam[i].win + Soccerteam[i].loss + Soccerteam[i].tie << "g (" << Soccerteam[i].win << "-" << Soccerteam[i].tie << "-" << Soccerteam[i].loss << "), ";
			cout << Soccerteam[i].goalScore - Soccerteam[i].goalAgainst << "gd (" << Soccerteam[i].goalScore << "-" << Soccerteam[i].goalAgainst << ")" << endl;
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}
