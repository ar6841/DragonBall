#include<fstream.h>
#include<dos.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream.h>
int status=0;
void save();
void filesave();
int menus();
void cleanup();
class character     //base class
{
	protected:
	int health;
	int damage;
	int block;
	int ki;
	int attack;
	char name[10];
	public:
	character()
	{
		attack=0;
		damage=0;
		ki=0;
		block=0;
		health=0;

	}
	void putki(int k)
	{
		ki=k;
	}
	void puthealth(int h) //function to put health
	{
		health=h;
	}
	int getki()   //function to return ki
	{
		return ki;
	}
	void charge() //function to charge
	{
		ki++;
		cout<<"\n";
		puts(name);
		cout<<" charged his Ki";
	}
	void hit(int x) //function to initialize damage
	{
		damage=x;
	}
	void newhealth()  //function to decrease health
	{
		health=health-damage;
		damage=0;
	}
	int getblock()  //function to return block
	{
		return block;
	}
	void kick()
	{
		attack=3;
		cout<<"\n";
		puts(name);
		cout<<" used kick";

	}
	void punch()
	{
		attack=2;
		cout<<"\n";
		puts(name);
		cout<<" used punch";
	}
	int getattack()  //function to return attack
	{
		return attack;
	}
	void reattack() //function to set attack to 0
	{
		attack=0;
	}
	int gethealth()  //function to return health
	{
		return health;
	}
	void blocked(int y)   //function called if characted got blocked
	{
		if(attack>y)
		{
			attack=attack-y;
		}
		else
		{
			attack=0;
		}

	}
	void display()   //function to display stats
	{
		cout<<"\n";
		puts(name);
		cout<<"\t\tHealth :"<<health;
		cout<<"\t\tKi :"<<ki;
	}

};
class goku:public character
{


	public:
	void gsave(goku &g) //function to save gokus stats
	{
		ofstream fout("goku.dat",ios::binary);//not opened in app mode so it overwrites
		fout.write((char*)&g,sizeof(g));
		fout.close();
	}
	void gload(goku &g)   //function to load gokus stats
	{
		ifstream fin("goku.dat",ios::binary);
		if(!fin)
		{
			delay(1000);
			cout<<"\nDefault values used for Goku";
		}
		else
		{
			fin.read((char*)&g,sizeof(g));
		}
		fin.close();
	}
	goku()           //constructor for goku
	{
		strcpy(name,"Goku");
		if(status==0)
		{
			health=50;
			block=5;
		}
		else if(status==1)
		{
			health=75;
			block=10;

		}
		else if(status==2)
		{
			health=100;
			block=15;
		}

	}
	void kamehameha();
	void info();
	void spiritbomb();

};
void goku::spiritbomb()       //function for attack spirit bomb
{
	switch(status)
	{
		case 1:
		{
			if(ki>2)
			{
				attack=35;
				ki=ki-3;
				cout<<"\nGoku used spirit bomb!";

			}
			else
			{
				cout<<"\nNot enough ki for spiritbomb.";

			}
			break;
		}
		case 2:
		{
			if(ki>3)
			{
				attack=40;
				ki=ki-4;
				cout<<"\nGoku used Spirit Bomb!";
			}
			else
			{
				cout<<"\nNot enought Ki available for Spirit bomb!";
			}
			break;

		}

	}
}
void goku::info()       //function to display info about goku
{
	clrscr();
	cout<<"\nPress required keys to play\nDo not press enter after each turn";
	switch(status)
	{
		case 0:
		{
			cout<<"\nFight Difficulty: EASY";
			cout<<"\nBlock strength="<<getblock();
			cout<<"\nSPECIAL ATTACKS REQUIRE KI";
			cout<<"\nSPECIAL ATTACKS AVAILABLE:\n1.Kamehameha\tKi required=1\tDamage=10 HP";
			break;
		}
		case 1:
		{
			cout<<"\nFight Difficulty: MEDIUM";
			cout<<"\nBlock strength="<<getblock();
			cout<<"\nSPECIAL ATTACKS AVAILABLE:\n1.Kamehameha\tKi required=2\tDamage=15 HP";
			cout<<"\n2.Spirit bomb\tKi required=3\tDamage=35";
			break;
		}
		case 2:
		{
			cout<<"\nFight Difficulty: HARD";
			cout<<"\nBlock strength="<<getblock();
			cout<<"\nSPECIAL ATTACKAS AVAILABLE\n1.Kamehameha\tKi Required=3\tDamage=20 HP";
			cout<<"\n2.Spirit bomb\tKi required=4\tDamage=40";
			break;
		}
	}
	cout<<"\nPress anything to continue";
	getch();
}
void goku::kamehameha()
{
	switch(status)
	{
		case 0:
		{
			if(ki>0)
			{
				attack=10;
				ki--;
				cout<<"\nGoku used kamehameha!";
			}
			else
			{
				cout<<"\nNo Ki available";

			}
			break;
		}
		case 1:
		{
			if(ki>1)
			{
				attack=15;
				ki=ki-2;
				cout<<"\nGoku used kamehameha";
			}
			else
			{
				cout<<"\nNot enough Ki available";
			}
			break;
		}
		case 2:
		{
			if(ki>2)
			{
				attack=20;
				ki=ki-3;
				cout<<"\nGoku used Kamehameha";
			}
			else
				cout<<"\nNot enought Ki available";
			break;
		}
	}
}
class raditz:public character
{

	public:
	void rsave(raditz &r)
	{
		ofstream fout("raditz.dat",ios::binary);
		fout.write((char*)&r,sizeof(r));
		fout.close();
	}
	void rload(raditz &r)
	{
		ifstream fin("raditz.dat",ios::binary);
		if(!fin)
		{
			cout<<"\nDefault values used for Raditz";
		}
		else
		{
			fin.read((char*)&r,sizeof(r));
		}
		fin.close();
	}
	void doublesunday()
	{
		if(ki>0)
		{
			attack=10;
			ki--;
			cout<<"\nRadits used double sunday!";
		}
		else
		{
			cout<<"\nRaditz tried to use double sunday but didnt have enough ki";
		}
	}
	raditz()
	{
		strcpy(name,"Raditz");
		health=50;
		block=10;
	}
	void info()
	{
		cout<<"\nNAME:";
		puts(name);
		cout<<"\nSpecial moves:";
		cout<<"\nDOUBLE SUNDAY\tDamage=10";
		cout<<"\nBlock strength="<<getblock();
		cout<<"\nPress an key to continue";
		getch();
	}

};
class freeza:public character
{
	public:
	void fsave(freeza &f)
	{
		ofstream fout("freeza.dat",ios::binary);
		fout.write((char*)&f,sizeof(f));
		fout.close();
	}
	void fload(freeza &f)
	{
		ifstream fin("freeza.dat",ios::binary);
		if(!fin)
		{
			cout<<"\nDefault values used for Freeza";
		}
		else
		{
			fin.read((char*)&f,sizeof(f));
		}
		fin.close();
	}
	freeza()
	{
		strcpy(name,"Freeza");
		health=200;
		block=30;
	}
	void eyelaser()
	{
		if(ki>1)
		{
			attack=25;
			ki=ki-2;
			cout<<"\nFreeza uses eyelaser.";
		}
		else
		{
			cout<<"\nFreeza tried to use eyelaser but his Ki was low";
		}
	}
	void deathcomet()
	{
		if(ki>2)
		{
			attack=35;
			ki=ki-3;
			cout<<"\nFreeza uses deathcomet.";
		}
		else
		{
			cout<<"\nFreeza tried to use deathcomet but his Ki was too low";
		}
	}
	void deathball()
	{
		if(ki>3)
		{
			attack=45;
			ki=ki-4;
			cout<<"\nFreeza uses deathball!";
		}
		else
		{
			cout<<"\nFreeza tried to use deathball but his ki was too low";
		}
	}
	void charge()
	{
		ki=ki+4;
		cout<<"\n";
		puts(name);
		cout<<"\nCharged his Ki";
	}
	void info()
	{
		cout<<"\nNAME:";
		puts(name);
		cout<<"\nSpecial moves:";
		cout<<"\n1.Eyelaser\tDamage=25\n2.Deathcomet\tDamage=35\n3.DeathBall\tDamage=45";
		cout<<"\nBlock strength="<<getblock();
		cout<<"\nPress an key to continue";
		getch();
	}
};
class vegeta:public character
{
	public:
	void vsave(vegeta &v)
	{
		ofstream fout("vegeta.dat",ios::binary);
		fout.write((char*)&v,sizeof(v));
		fout.close();
	}
	void vload(vegeta &v)
	{
		ifstream fin("vegeta.dat",ios::binary);
		if(!fin)
		{
			cout<<"\nDefault values used for vegeta";
		}
		else
		{
			fin.read((char*)&v,sizeof(v));
		}
		fin.close();
	}
	vegeta()
	{
		strcpy(name,"Vegeta");
		health=100;
		block=20;
	}
	void galickgun()
	{
		if(ki>1)
		{
			attack=20;
			ki=ki-2;
			cout<<"\nVegeta uses galickgun.";
		}
		else
		{
			cout<<"\nVegeta tried to use Galick gun but his Ki was low";
		}
	}
	void finalflash()
	{
		if(ki>2)
		{
			attack=25;
			ki=ki-3;
			cout<<"\nVegeta uses finalflash.";
		}
		else
		{
			cout<<"\nVegeta tried to use final flash but his Ki was too low";
		}
	}
	void bigbang()
	{
		if(ki>3)
		{
			attack=30;
			ki=ki-4;
			cout<<"\nVegeta uses bigbangattck";
		}
		else
		{
			cout<<"\nVegeta tried to use bigbangattack but his ki was too low";
		}
	}
	void charge()
	{
		ki=ki+2;
		cout<<"\n";
		puts(name);
		cout<<"\nCharged his Ki";
	}
	void info()
	{
		cout<<"\nNAME:";
		puts(name);
		cout<<"\nSpecial moves:";
		cout<<"\n1.GalickGun\tDamage=20\n2.Final Flash\tDamage=25\n3.Bigbang Attack\tDamage=30";
		cout<<"\nBlock strength="<<getblock();
		cout<<"\nPress an key to continue";
		getch();
	}
};
int probability(raditz &r,goku &g);
int probability(vegeta &v,goku &g);
int probability(freeza &f,goku &g);
void fight0() //function for first fight
{
	clrscr();
	goku g;
	raditz r;
	cout<<"\nWould you like to continue from previous point?\n1.Yes\n2.No";
	switch(menus())
	{
		case 1:
		{
			g.gload(g);
			r.rload(r);
		}
		case 2:cleanup();
			break;
		default:
		{
			cout<<"\nWrong option!";
			delay(2000);
			fight0();
		}
	}
	cout<<"\nGoku vs Raditz!!";
	while(g.gethealth()>0&&r.gethealth()>0)
	{
		int flag=0;
		g.display();
		r.display();
		int move=probability(r,g);
		cout<<"\n1.Kick\n2.Punch\n3.Kamehameha\n4.Block\n5.Charge ki\n6.Save and quit\n";
		switch(menus())
		{
			case 1:g.kick();
				break;
			case 2:g.punch();
				break;
			case 3:g.kamehameha();
				break;
			case 4:
			{
				cout<<"\nGoku blocks";
				flag=1;
				break;
			}
			case 5:g.charge();
				break;
			case 6:
			{
				g.gsave(g);
				r.rsave(r);
				exit(0);
			}
			default:
			{
				cout<<"\nWrong option! Chance lost!";
			}
		}

		switch(move)
		{
			case 0:
			{
				r.kick();
				break;
			}
			case 1:
			{
				r.punch();
				break;
			}
			case 2:
			{
				r.doublesunday();
				break;
			}
			case 3:
			{
				g.blocked(r.getblock());
				cout<<"\nRaditz blocks";
				break;
			}
			case 4:
			{
				r.charge();
				break;
			}
		}
		if(flag==1)
		{
			r.blocked(g.getblock());
		}
		r.hit(g.getattack());
		r.newhealth();
		g.hit(r.getattack());
		g.newhealth();
		r.reattack();
		g.reattack();
		delay(1000);
		clrscr();
		if(g.gethealth()<=0)
		{
			cout<<"\nYou died!";
			cleanup();
			save();
		}
		if(r.gethealth()<=0)
		{
			cout<<"\nRaditz died";
			cout<<"\nYOU WIN!!";
			cleanup();
			status++;
			save();
		}

	}
}
void fight1()
{
	clrscr();
	goku g;
	vegeta v;
	cout<<"\nWould you like to continue from previous point?\n1.Yes\n2.No";
	switch(menus())
	{
		case 1:
		{
			g.gload(g);
			v.vload(v);
		}
		case 2:cleanup();
			break;
		default:
		{
			cout<<"\nWrong option!";
			delay(2000);
			fight1();
		}
	}
	cout<<"\nGoku Vs Vegeta";
	while(g.gethealth()>0&&v.gethealth()>0)
	{
		g.display();
		v.display();
		int flag=0;
		int move=probability(v,g);
		cout<<"\n1.Kick\n2.Punch\n3.Kamehameha\n4.Block\n5.Charge ki\n6.Spirit bomb\n7.Save and quit\n";
		switch(menus())
		{
			case 1:g.kick();
				break;
			case 2:g.punch();
				break;
			case 3:g.kamehameha();
				break;
			case 4:flag=1;
				break;
			case 5:g.charge();
				break;
			case 6:g.spiritbomb();
				break;
			case 7:
			{
				g.gsave(g);
				v.vsave(v);
				exit(0);
			}
			default:
			{
				cout<<"\nWrong option! Chance lost!";
			}
		}
		switch(move)
		{
			case 0:
			{
				v.kick();
				break;
			}
			case 1:
			{
				v.punch();
				break;
			}
			case 2:
			{
				v.galickgun();
				break;
			}
			case 3:
			{
			       v.finalflash();
			       break;
			}
			case 4:
			{
				v.bigbang();
				break;

			}
			case 5:
			{
				cout<<"\nVegeta blocks";
				g.blocked(v.getblock());
				break;
			}
			case 6:
			{
				v.charge();
				break;

			}
		}
		if(flag==1)
		{
			cout<<"\nGoku blocks!";
			v.blocked(g.getblock());
		}
		v.hit(g.getattack());
		v.newhealth();
		g.hit(v.getattack());
		g.newhealth();
		v.reattack();
		g.reattack();
		delay(1000);
		clrscr();
		if(g.gethealth()<=0)
		{
			cout<<"\nYou died!";
			cleanup();
			save();
		}
		if(v.gethealth()<=0)
		{
			cout<<"\nVegeta was defeated";
			cout<<"\nYOU WIN!!";
			cleanup();
			status++;
			save();
		}

	}
}
void fight2()
{
	clrscr();
	goku g;
	freeza f;
	cout<<"\nWould you like to continue from previous point?\n1.Yes\n2.No";
	switch(menus())
	{
		case 1:
		{
			g.gload(g);
			f.fload(f);
		}
		case 2:cleanup();
			break;
		default:
		{
			cout<<"\nWrong option!";
			delay(2000);
			fight2();
		}
	}
	cout<<"\nGoku Vs Freeza";
	while(g.gethealth()>0&&f.gethealth()>0)
	{
		g.display();
		f.display();
		int flag=0;
		int move=probability(f,g);
		cout<<"\n1.Kick\n2.Punch\n3.Kamehameha\n4.Block\n5.Charge ki\n6.Spirit bomb\n7.Save and quit\n";
		switch(menus())
		{
			case 1:g.kick();
				break;
			case 2:g.punch();
				break;
			case 3:g.kamehameha();
				break;
			case 4:flag=1;
				break;
			case 5:g.charge();
				break;
			case 6:g.spiritbomb();
				break;
			case 7:
			{
				g.gsave(g);
				f.fsave(f);
				exit(0);
			}
			default:
			{
				cout<<"\nWrong option! Chance lost!";
			}
		}
		switch(move)
		{
			case 0:
			{
				f.kick();
				break;
			}
			case 1:
			{
				f.punch();
				break;
			}
			case 2:
			{
				f.eyelaser();
				break;
			}
			case 3:
			{
				f.deathcomet();
			       break;
			}
			case 4:
			{
				f.deathball();
				break;

			}
			case 5:
			{
				cout<<"\nFreeza blocks";
				g.blocked(f.getblock());
				break;
			}
			case 6:
			{
				f.charge();
				break;

			}
		}
		if(flag==1)
		{
			cout<<"\nGoku blocks!";
			f.blocked(g.getblock());
		}


		f.hit(g.getattack());
		f.newhealth();
		g.hit(f.getattack());
		g.newhealth();
		f.reattack();
		g.reattack();
		delay(1000);
		clrscr();
		if(g.gethealth()<=0)
		{
			cout<<"\nYou died!";
			cleanup();
			save();
		}
		if(f.gethealth()<=0)
		{
			cout<<"\nFreeza was defeated";
			cout<<"\nYOU WIN!!";
			cleanup();
			status++;
			save();
		}

	}
}
void save() //function for menu to save
{
	cout<<"\n1.Save and quit\n2.Save and continue\n3.Continue\nChoice:";
	switch(menus())
	{
		case 1:
		{
			filesave();
			cout<<"\nQuitting";
			delay(1000);
			exit(0);
		}
		case 2:filesave();
			break;
		case 3:return;

		default:
		{
			cout<<"\nWrong option!";
			delay(1000);
			save();
		}
	}
}
void filesave()  //function to save point in game(fights won)
{
	ofstream fout("status.txt");
	if(!fout)
	{
		cout<<"\nFILE CORRUPTED!";
	}
	else
	{
		delay(300);
		cout<<"\nSaved!";
		fout<<status;
	}
	fout.close();
}
void load()  //function to load point in game(fights won)
{
	char txt;
	ifstream fin("status.txt");
	if(!fin)
	{
		cout<<"\nSAVE FILE DOES NOT EXIST!\nCreating file now!";
		cleanup();
		filesave();
		cout<<"\nFile created!";
	}
	else
	{
		fin>>txt;
		if(txt=='\0')
		{
			filesave();
			cout<<"\nSave file initialized!";
		}
		else if(txt-48>2)
		{
			cout<<"\nWould you like to restart the game?\n1.Yes\n2.No\nChoice:";
			switch(menus())
			{
				case 1:
				{
					ofstream fout("status.txt");
					fout<<status;
					cleanup();
					break;
				}
				case 2:exit(0);
				default:
				{
					cout<<"\nWrong option";
					load();
				}
			}
		}
		else
		{
			status=txt-48;
			cout<<"\nSave file loaded successfully";
		}
		fin.close();
	}
}
void reader(ifstream &fin)     //function to read story
{
	while(!fin.eof())
	{
		char *line;
		fin.getline(line,100);
		if(strcmpi(line,".")==0)
		{
			delay(1000);
		}
		else if(strcmpi(line,"..")==0)
		{
			delay(2000);
		}
		else if(strcmpi(line,"...")==0)
		{
			delay(2500);
		}
		else if(strcmpi(line,"....")==0)
		{
			delay(3000);
		}
		else if(strcmpi(line,"END")==0)
		{
			return;
		}
		else
		{
			cout<<"\n";
			puts(line);
		}
	}
}

void story()     //function for menu for story
{
	ifstream fin("story.txt");
	char *ch;
	delay(2000);
	cout<<"\nPress space to skip story, press anything else to read story..";
	char skip;
	skip=getch();
	if(skip==' ')
	{
		return;
	}
	else
	{
		while(!fin.eof())
		{
			fin.getline(ch,6);
			if(status==0)
			{
				if(strcmpi(ch,"ACT1")==0)
				{
					reader(fin);
				}
				else
					continue;
			}
			else if(status==1)
			{
				if(strcmpi(ch,"ACT2")==0)
				{
					reader(fin);
				}
				else
					continue;
			}
			else if(status==2)
			{
				if(strcmpi(ch,"ACT3")==0)
				{
					reader(fin);
				}
				else
					continue;
			}
		}
	}
	fin.close();
}
void cleanup()                          //function for deleting stats
{
	ifstream fin("goku.dat",ios::binary);
	if(!fin)
	{
		return;
	}
	else
	{
		switch(status)
		{
			case 0:remove("raditz.dat");
				break;
			case 1:remove("vegeta.dat");
				break;
			case 2:remove("freeza.dat");
				break;
		}
		remove("goku.dat");
	}
	fin.close();
}
int probability(raditz &r,goku &g)  //function to return biased value for raditz move
{
	srand(time(0));
	int x;
	if((r.gethealth()>25&&r.getki()>0)||g.gethealth()<=10)
	{
		x=rand()%7-2;
		if(x<0)
			x=x*(-1);
	}
	else if(r.gethealth()>=25&&r.getki()==0)
	{
		x=rand()%5+rand()%3;
		if(x>4)
			x=4;
	}
	else if(r.gethealth()<10||g.getki()>=3)
	{
		x=rand()%8-3;
		if(x<0)
			x=3;
	}
	else
	{
		x=rand()%5;
	}
	return x;
}
int probability(vegeta &v,goku &g)
{
	srand(time(0));
	int x;
	if((v.gethealth()>50&&v.getki()>0)||g.gethealth()<=25)
	{
		x=rand()%11-4;
		if(x<0)
			x=x*(-1);
	}
	else if(v.gethealth()>50&&v.getki()==0)
	{
		x=rand()%7+rand()%4;
		if(x>6)
			x=6;
	}
	else if(v.gethealth()<20||g.getki()>=4)
	{
		x=rand()%12-5;
		if(x<0)
			x=5;
	}
	else
	{
		x=rand()%7;
	}
	return x;
}
int probability(freeza &f,goku &g)
{
	randomize();
	int x;
	if((f.gethealth()>50&&f.getki()>0)||g.gethealth()<=25)
	{
		x=rand()%11-4;
		if(x<0)
			x=x*(-1);
	}
	else if(f.gethealth()>50&&f.getki()==0)
	{
		x=rand()%7+rand()%4;
		if(x>6)
			x=6;
	}
	else if(f.gethealth()<20||g.getki()>=4)
	{
		x=rand()%12-5;
		if(x<0)
			x=5;
	}
	else
	{
		x=rand()%7;
	}
	return x;
}
void putinfo()   //function for menu for info
{
	goku g;
	vegeta v;
	freeza f;
	raditz r;
	char c;
	cout<<"\nWould you like to have info about current battle?";
	cout<<"\n1.Yes\n2.No";
	switch(menus())
	{
		case 1:
		{
			g.info();
			cout<<"\nENEMY\n";
			switch(status)
			{
				case 0:r.info();
					break;
				case 1:v.info();
					break;
				case 2:f.info();
					break;
			}
		}
		case 2:return;
		default:
		{
			cout<<"\nWRONG OPTION!";
			putinfo();
		}
	  }
}
int menus() //function to return integer value in menus
{
	char c;
	c=getch();
	if(isdigit(c))
	{
		int x=c-48;
		return x;
	}
	else
	{
		return 0;
	}
}

void main()
{
	clrscr();
	load();
	while(status<3)
	{
		story();
		putinfo();
		switch(status)
		{
			case 0:fight0();
				break;
			case 1:fight1();
				break;
			case 2:fight2();
				break;
		}

	}
}












