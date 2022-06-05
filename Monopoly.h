#pragma once
#pragma warning(disable: 4996)
#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cstdlib>
#include<time.h>
using namespace std;

class Player
{
	int id;
	int balance;
	int Jail;
	int bk;
	int Jailcard;
public:
	Player();
	Player(int id);
	void setJailcard(int card);
	int getcard();
	void setid(int id);
	void setbal(int bal);
	void setJail(int j);
	void setbk(int b);
	int getid();
	int& getbal();
	int getJail();
	int getbk();
};

class Property
{
	int pid;
	int group;
	char* name;
	int cost;
	int rent;
	bool status;
	int houses;
	int wifi;
	int gas;
	int electricity;
	int x;
	int y;
	int own;
public:
	Property();
	friend istream& operator >>(istream& in, Property& obj);
	friend ostream& operator <<(ostream& out, Property& obj);
	int get_pid();
	int get_group();
	char* get_name();
	int get_cost();
	int get_rent();
	bool get_status();
	int get_houses();
	int get_wifi();
	int get_gas();
	int get_elec();
	int get_x();
	int get_y();
	int get_own();
	void setrent(int r);
	void setstatus(bool s);
	void sethouses(int h);
	void setwifi(int w);
	void setgas(int g);
	void setelec(int e);
	void setowner(int o);
	void mortgage(int Playerid, int& bal);
	~Property();
};

class GO
{
	int gid;
	int pay;
	int x;
	int y;
public:
	GO();
	int get_GOx();
	int get_GOy();
	int get_pay();
};

class Chest
{
	int cid;
	int ctype;
	int x;
	int y;
public:
	friend istream& operator >>(istream& in, Chest& obj);
	Chest();
	int get_cx();
	int get_cy();
	int get_cid();
	int get_ctype();
};

class Jail
{
	int jid;
	int jtype;
	int x;
	int y;
public:
	Jail();
	void set_Jail(int ji, int jtypes, int x_axis, int y_axis);
	int get_jid();
	int get_jtype();
	int get_jx();
	int get_jy();
};

class FreePark
{
	int fid;
	int x;
	int y;
	int paypark;
public:
	FreePark();
	int get_fid();
	int get_px();
	int  get_py();
	int  get_paypark();
};

class Tax
{
	int tid;
	int tpay;
	int x;
	int y;
public:
	Tax();
	void setTax(int t, int Taxpay, int x_axis, int y_axis);
	int get_tid();
	int get_tpay();
	int get_tx();
	int get_ty();
};

class Chance
{
	int number;
	char* command;
public:
	Chance();
	friend istream& operator >>(istream& in, Chance& obj);
	int getnum();
	char* getcommand();
	~Chance();
};

class Game
{
	Chance* chance;
	Player* play;
	Property* p;
	GO start;
	Jail* j;
	Chest* c;
	FreePark fp;
	Tax lTax;
	Tax pTax;
	int chancecheck;
public:
	Game();
	~Game();
	bool GroupCheck(int pid, int plr); // pid = propertyid & plr = Player id
	void Build(int pid, int plr, sf::Window& window); // pid = propertyid & plr = Player id
	void Upgrade(int pid, int plr, sf::Window& window); // pid = propertyid & plr = Player id
	void Doublerent(int pid, int plr); // pid = propertyid & plr = Player id
	void Buy(int position, int plr, sf::Window& window, int& ups);
	void LandTax(int plr);
	void Chances(int& position, int person);
	void CommunityChest(int& position, int person);
	void PropertyTax(int plr);
	void win(int& x);
	void Graphic();
	void mortcheck(int playercheck, int& selector, sf::Window &window);
};