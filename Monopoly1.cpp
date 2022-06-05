#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cstdlib>
#include<time.h>
#include"Monopoly.h"
using namespace std;

Player::Player()
{
	id = 0;
	balance = 5000;
	Jail = 0;
	bk = 0;
	Jailcard = 0;
}
Player::Player(int id)
{
	this->id = id;
	balance = 5000;
	Jail = 0;
	bk = 0;
	Jailcard = 0;
}
void Player::setJailcard(int card)
{
	Jailcard = card;
}
int Player::getcard()
{
	return Jailcard;
}
void Player::setid(int id)
{
	this->id = id;
}
void Player::setbal(int bal)
{
	balance = bal;
}
void Player::setJail(int j)
{
	Jail = j;
}
void Player::setbk(int b)
{
	bk = b;
}
int Player::getid()
{
	return id;
}
int& Player::getbal()
{
	return balance;
}
int Player::getJail()
{
	return Jail;
}
int Player::getbk()
{
	return bk;
}

Property::Property()
{
	pid = 0;
	group = 0;
	name = new char[25];
	cost = 0;
	rent = 0;
	status = 0;
	houses = 0;
	wifi = 0;
	gas = 0;
	electricity = 0;
	x = 0;
	y = 0;
	own = 0;
}
int Property::get_pid()
{
	return pid;
}
int Property::get_group()
{
	return group;
}
char* Property::get_name()
{
	return name;
}
int Property::get_cost()
{
	return cost;
}
int Property::get_rent()
{
	return rent;
}
bool Property::get_status()
{
	return status;
}
int Property::get_houses()
{
	return houses;
}
int Property::get_wifi()
{
	return wifi;
}
int Property::get_gas()
{
	return gas;
}
int Property::get_elec()
{
	return electricity;
}
int Property::get_x()
{
	return x;
}
int Property::get_y()
{
	return y;
}
int Property::get_own()
{
	return own;
}
void Property::setrent(int r)
{
	rent = r;
}
void Property::setstatus(bool s)
{
	status = s;
}
void Property::sethouses(int h)
{
	houses = h;
}
void Property::setwifi(int w)
{
	wifi = w;
}
void Property::setgas(int g)
{
	gas = g;
}
void Property::setelec(int e)
{
	electricity = e;
}
void Property::setowner(int o)
{
	own = o;
}
void Property::mortgage(int Playerid, int& bal)
{
	if (status == 1)
	{
		cout << "Status : Mortgaged" << endl;
	}
	else if (status == 0)
	{
		cout << "Status : Unmortgaged" << endl;
	}

	if (own == Playerid)
	{
		int check = 0;
		while (check == 0)
		{
			cout << "Enter 1 to mortgage 2 to unmortgage " << endl;
			int opt;
			cin >> opt;
			if (opt == 1)
			{
				if (status == 0)
				{
					cout << "This Propert  has mortgage value : " << (cost / 2) << endl;
					bal = bal + (cost / 2);
					cout << "New Balance of Player " << Playerid << " is : " << bal << endl;
					check = 1;
				}
				else if (status == 1)
				{
					cout << "The propert is already mortgaged, you can enter again  " << endl;
				}
			}
			else if (opt == 2)
			{
				if (status == 1 && own == Playerid)
				{
					cout << "This Propert  has unmortgage value : " << ((cost / 2) + ((cost / 2) * 0.2)) << endl;
					bal = bal - ((cost / 2) + ((cost / 2) * 0.2));
					cout << "New Balance of Player " << Playerid << " is : " << bal << endl;
					check = 1;
				}
				else if (status == 0)
				{
					cout << "The propert is already unmortgaged, you can enter again  " << endl;
				}
			}
		}
	}
	else
	{
		cout << "This property is not owned by you" << endl;
	}

}
istream& operator >>(istream& in, Property& obj)
{
	in >> obj.pid;
	in >> obj.group;
	in >> obj.name;
	in >> obj.cost;
	in >> obj.rent;
	in >> obj.status;
	in >> obj.houses;
	in >> obj.wifi;
	in >> obj.gas;
	in >> obj.electricity;
	in >> obj.x;
	in >> obj.y;
	in >> obj.own;
	return in;
}
ostream& operator <<(ostream& out, Property& obj)
{
	out << obj.pid << " ";
	out << obj.group << " ";
	out << obj.name << " ";
	out << obj.cost << " ";
	out << obj.rent << " ";
	out << obj.status << " ";
	out << obj.houses << " ";
	out << obj.wifi << " ";
	out << obj.gas << " ";
	out << obj.electricity << " ";
	out << obj.x << " ";
	out << obj.y << " ";
	out << obj.own << endl;
	return out;
}
Property::~Property()
{
	delete[]name;
}

GO::GO()
{
	gid = 0;
	pay = 500;
	x = 75;
	y = 4;
}
int GO::get_GOx()
{
	return x;
}
int GO::get_GOy()
{
	return y;
}
int GO::get_pay()
{
	return pay;
}

Chest::Chest()
{
	cid = 0;
	ctype = 0;
	x = 0;
	y = 0;
}
int Chest::get_cx()
{
	return x;
}
int Chest::get_cy()
{
	return y;
}
int Chest::get_cid()
{
	return cid;
}
int Chest::get_ctype()
{
	return ctype;
}
istream& operator >>(istream& in, Chest& obj)
{
	in >> obj.cid;
	in >> obj.ctype;
	in >> obj.x;
	in >> obj.y;
	return in;
}

Jail::Jail()
{
	jid = 0;
	jtype = 0;
	x = 0;
	y = 0;
}
void Jail::set_Jail(int ji, int jtypes, int x_axis, int y_axis)
{
	jid = ji;
	jtype = jtypes;
	x = x_axis;
	y = y_axis;
}
int Jail::get_jid()
{
	return jid;
}
int Jail::get_jtype()
{
	return jtype;
}
int Jail::get_jx()
{
	return x;
}
int Jail::get_jy()
{
	return y;
}

FreePark::FreePark()
{
	fid = 20;
	x = 657;
	y = 652;
	paypark = 10;
}
int FreePark::get_fid()
{
	return fid;
}
int FreePark::get_px()
{
	return x;
}
int  FreePark::get_py()
{
	return y;
}
int  FreePark::get_paypark()
{
	return paypark;
}

Tax::Tax()
{
	tid = 0;
	tpay = 0;
	x = 0;
	y = 0;
}
void Tax::setTax(int t, int Taxpay, int x_axis, int y_axis)
{
	tid = t;
	tpay = Taxpay;
	x = x_axis;
	y = y_axis;
}
int Tax::get_tid()
{
	return tid;
}
int Tax::get_tpay()
{
	return tpay;
}
int Tax::get_tx()
{
	return x;
}
int Tax::get_ty()
{
	return y;
}

Chance::Chance()
{
	number = 0;
	command = new char[200];
}
istream& operator >>(istream& in, Chance& obj)
{
	in >> obj.number;
	in >> obj.command;
	return in;
}
int Chance::getnum()
{
	return number;
}
char* Chance::getcommand()
{
	return command;
}
Chance::~Chance()
{
	delete[] command;
	command = nullptr;
}

Game::Game()
{
	chancecheck = 1;
	chance = new Chance[15];
	play = new Player[4];
	play[0].setid(1);
	play[1].setid(2);
	play[2].setid(3);
	play[3].setid(4);
	p = new Property[28];
	j = new Jail[2];
	j[0].set_Jail(10, 1, 686, 4);
	j[1].set_Jail(30, 2, 0, 640);
	c = new Chest[6];
	lTax.setTax(4, 20, 310, 4);
	pTax.setTax(38, 10, 0, 198);
}
Game::~Game()
{
	delete[]play;
	delete[]p;
	delete[]j;
	delete[]c;
}
bool Game::GroupCheck(int pid, int plr) // pid = propertyid & plr = Player id
{
	if (p[pid].get_group() == p[0].get_group() && p[pid].get_group() == p[1].get_group() && p[0].get_own() == plr && p[1].get_own() == plr)
	{
		return true;
	}
	else if (p[pid].get_group() == p[3].get_group() && p[pid].get_group() == p[4].get_group() && p[pid].get_group() == p[5].get_group() && p[3].get_own() == plr && p[4].get_own() == plr && p[5].get_own() == plr)
	{
		return true;
	}
	else if (p[pid].get_group() == p[6].get_group() && p[pid].get_group() == p[8].get_group() && p[pid].get_group() == p[9].get_group() && p[6].get_own() == plr && p[8].get_own() == plr && p[9].get_own() == plr)
	{
		return true;
	}
	else if (p[pid].get_group() == p[11].get_group() && p[pid].get_group() == p[12].get_group() && p[pid].get_group() == p[13].get_group() && p[11].get_own() == plr && p[12].get_own() == plr && p[13].get_own() == plr)
	{
		return true;
	}
	else if (p[pid].get_group() == p[14].get_group() && p[pid].get_group() == p[15].get_group() && p[pid].get_group() == p[16].get_group() && p[14].get_own() == plr && p[15].get_own() == plr && p[16].get_own() == plr)
	{
		return true;
	}
	else if (p[pid].get_group() == p[18].get_group() && p[pid].get_group() == p[19].get_group() && p[pid].get_group() == p[21].get_group() && p[18].get_own() == plr && p[19].get_own() == plr && p[21].get_own() == plr)
	{
		return true;
	}
	else if (p[pid].get_group() == p[22].get_group() && p[pid].get_group() == p[23].get_group() && p[pid].get_group() == p[24].get_group() && p[22].get_own() == plr && p[23].get_own() == plr && p[24].get_own() == plr)
	{
		return true;
	}
	return false;
}
void Game::Build(int pid, int plr, sf::Window& window) // pid = propertyid & plr = Player id
{
	if (p[pid].get_houses() > 4)
	{
		if (p[pid].get_houses() == 0)
		{
			cout << "No Houses Built" << endl;
		}
		else if (p[pid].get_houses() > 0)
		{
			cout << "Houses are " << p[pid].get_houses() << endl;
		}
	}
	else if (p[pid].get_houses() == 4)
	{
		cout << "Shops : 1" << endl;
	}
	else if (p[pid].get_houses() == 5)
	{
		cout << "Hotel : 1" << endl;
	}
	cout << "Which property you want to Upgrade" << endl;
	int i = 0;
	cin >> i;
	int j = 0;
	for (; j < 28; j++)
	{
		if (i == p[j].get_pid())
		{
			pid = j;

		}
	}
	if (GroupCheck(pid, plr))
	{
		cout << "Do you want to Build(1) or UnBuild(2) : exit(0) " << endl;
		int opt = -1;

		while (opt != 0)
		{
			cout << "Do you want to Build(1) or UnBuild(2) : exit(0) " << endl;
			cin >> opt;
			if (opt == 1)
			{
				if (p[pid].get_houses() <= 5)
				{
					p[pid].sethouses(p[pid].get_houses() + 1);
					//p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.3));
					if (p[pid].get_houses() <= 3)
					{
						p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.3));
					}
					else if (p[pid].get_houses() == 4)
					{
						p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.6));
					}
					else
					{
						p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.8));
					}
				}

				else
				{
					cout << "Already reached the max limit" << endl;
				}
			}
			else if (opt == 2)
			{
				if (p[pid].get_houses() >= 1)
				{
					p[pid].sethouses(p[pid].get_houses() - 1);
					if (p[pid].get_houses() <= 2)
					{
						p[pid].setrent(p[pid].get_rent() - (p[pid].get_rent() * 0.3));
					}
					else if (p[pid].get_houses() == 3)
					{
						p[pid].setrent(p[pid].get_rent() - (p[pid].get_rent() * 0.6));
					}
					else if (p[pid].get_houses() == 4)
					{
						p[pid].setrent(p[pid].get_rent() - (p[pid].get_rent() * 0.8));
					}
				}
				else
				{
					cout << "Already reached the min limit" << endl;
				}
			}
		}
	}
}
void Game::Upgrade(int pid, int plr, sf::Window& window) // pid = propertyid & plr = Player id
{
	cout << " Wifi : " << p[pid].get_wifi() << endl;
	cout << " Gas : " << p[pid].get_gas() << endl;
	cout << " Electricity : " << p[pid].get_elec() << endl;
	cout << "Which property you want to UPGRADE" << endl;
	int i = 0;
	cin >> i;
	int j = 0;
	for (; j < 28; j++)
	{
		if (i == p[j].get_pid())
		{
			pid = j;

		}
	}
	if (GroupCheck(pid, plr))
	{
		int u = -1;
		int bu = 0;
		cout << " Press W for wifi : G for gas : E for electricity : X to exit" << endl;

		while (window.isOpen() && bu == 0)
		{
			sf::Event eve;
			while (window.pollEvent(eve))
			{
				switch (eve.key.code)
				{
				case sf::Keyboard::W:

					if (p[pid].get_wifi() == 0)
					{
						cout << "wifi is for : 30 PKR " << endl;
						play[plr].setbal(play[plr].getbal() - 30);
						p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.1));
						p[pid].setwifi(1);
						bu = 1;
					}
					else
					{
						bu = 1;
						cout << "You already have WIFI" << endl;
					}
					break;
				case sf::Keyboard::G:

					if (p[pid].get_gas() == 0)
					{
						cout << "gas is for : 50 PKR " << endl;
						play[plr].setbal(play[plr].getbal() - 50);
						p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.2));
						p[pid].setgas(1);
						bu = 1;
					}
					else
					{
						cout << "You already have GAS" << endl;
						bu = 1;
					}
					break;

				case sf::Keyboard::E:
					if (p[pid].get_elec() == 0)
					{
						cout << "Electricity is for : 50 PKR " << endl;
						play[plr].setbal(play[plr].getbal() - 50);
						p[pid].setrent(p[pid].get_rent() + (p[pid].get_rent() * 0.2));
						p[pid].setelec(1);
						bu = 1;
					}
					else
					{
						cout << "You already have Electricity  " << endl;
						bu = 1;
					}
					break;
				case sf::Keyboard::X:
					u = 0;
					break;
				}
			}
		}
	}
	else
	{
		cout << " You can't Upgrade this property ";
	}


}
void Game::Doublerent(int pid, int plr) // pid = propertyid & plr = Player id
{


	if (GroupCheck(pid, plr))
	{
		int x = 0;
		cout << "Enter 1 to double the rent else 0" << endl;
		cin >> x;

		if (GroupCheck(pid, plr) && x == 1)
		{
			cout << "Current Rent is : " << p[pid].get_rent() << endl;
			p[pid].setrent(p[pid].get_rent() * 2);
			cout << "Double Rent is : " << p[pid].get_rent() << endl;
		}
		else if (x != 1)
		{
			cout << " OK NP " << endl;
		}
		else
		{
			cout << "You are not allowed to double the rent" << endl;
		}
	}
}
void Game::Buy(int position, int plr, sf::Window& window, int& ups)
{
	int arr[4];
	int highestbid = 0;
	int hbider = 0;
	int w = 0;

	cout << "Position " << position << endl;
	int select;
	cout << "Cash: " << play[plr - 1].getbal() << endl;    // starting Player from 1-4 so using plr-1

	if (play[plr - 1].getbal() < p[position].get_cost())
	{
		cout << "You cant Buy this property not Enough Balance " << endl;
	}

	if (p[position].get_own() == 0)
	{
		if (play[plr - 1].getbal() > p[position].get_cost())
		{
			cout << "You can Buy this property for: " << p[position].get_cost() << endl;
			cout << "Press B to Buy: " << endl;
			cout << "Press V if dont want to Buy" << endl;
			int bu = 0;
			while (window.isOpen() && bu == 0)
			{
				sf::Event eve;
				while (window.pollEvent(eve))
				{
					switch (eve.key.code)
					{
					case sf::Keyboard::B:

						if (bu == 0)
						{
							play[plr - 1].setbal(play[plr - 1].getbal() - p[position].get_cost());
							p[position].setowner(plr);
							cout << "owner" << p[position].get_own() << endl;
							cout << "Remaining balance:  " << play[plr - 1].getbal() << endl;
							bu = 1;

						}
						break;
					case sf::Keyboard::V:
						//system("cls");
						
						if (w == 0)
						{

							for (int i = 0; i < 4; i++)
							{
								cout << "Player " << i << " bid : ";
								cin >> arr[i];
								if (arr[i] < play[i].getbal() && arr[i] > highestbid)
								{
									highestbid = arr[i];
									hbider = i;
								}

							}
							play[hbider].setbal(play[hbider].getbal() - highestbid);
							p[position].setowner(hbider + 1);
							cout << "owner" << p[position].get_own() << endl;
							cout << "Remaining balance:  " << play[hbider].getbal() << endl;
							w = 1;
						}
						
						
						bu = 2;
						break;
					}
				}
			}
		}
	}

	else if (p[position].get_own() != 0 && p[position].get_own() != plr)
	{
		int remainingbal = 0;
		cout << "Rent pay: " << p[position].get_rent() << endl;
		int rent = play[(p[position].get_own()) - 1].getbal();
		rent = rent + p[position].get_rent();
		remainingbal = play[plr - 1].getbal() - p[position].get_rent();
		play[plr - 1].setbal(remainingbal);
		play[(p[position].get_own()) - 1].setbal(rent);
		cout << "Player " << p[position].get_own() << " Balance: " << play[(p[position].get_own()) - 1].getbal() << endl;
		cout << "Player " << plr << " Balance: " << play[plr - 1].getbal() << endl;
	}

	int bx = 0;
	cout << "press U to Upgrade Or H for building houses or s to skip" << endl;
	while (window.isOpen() && bx == 0)
	{
		sf::Event eve;
		while (window.pollEvent(eve))
		{
			switch (eve.key.code)
			{

			case sf::Keyboard::U:
				bx = 2;
				ups = 1;
				break;
			case sf::Keyboard::H:
				bx = 2;
				ups = 2;
				break;
			case sf::Keyboard::S:
				system("cls");
				bx = 2;
			}
		}
	}


}
void Game::LandTax(int plr)
{
	int sum = 0;
	for (int i = 0; i < 28; i++)
	{
		if (p[i].get_own() == plr)
		{
			sum = sum + p[i].get_cost();
		}

	}

	cout << "Player " << plr << " Have to give land Tax : " << (sum * 0.2) << endl;
	play[plr - 1].setbal(play[plr - 1].getbal() - (sum * 0.2));
	cout << "Player " << plr << " Remaining Balance: " << play[plr - 1].getbal() << endl;
}
void Game::Chances(int& position, int person)
{
	ifstream fin;
	fin.open("Chance.txt", ios::app);
	if (fin)
	{
		for (int i = 0; i < 15; i++)
		{
			fin >> chance[i];
		}
	}
	fin.close();

	int v1;
	v1 = (rand() % 15);

	if (chance[v1].getnum() == 1)
	{
		position = 0;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 2)
	{
		position = 26;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 3)
	{
		if (position == 8)
			position = 12;
		else if (position == 22)
			position = 28;
		else if (position == 36)
			position = 37;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 4)
	{
		if (position == 8)
			position = 15;
		else if (position == 22)
			position = 25;
		else if (position == 36)
			position = 5;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 5)
	{
		if (position == 8)
			position = 15;
		else if (position == 22)
			position = 25;
		else if (position == 36)
			position = 5;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 6)
	{
		if (position > 21)
		{
			play[person - 1].setbal(play[person - 1].getbal() + 300);
		}
		position = 21;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 7)
	{
		play[person - 1].setbal(play[person - 1].getbal() + 100);
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 8)
	{
		play[person - 1].setJailcard(1);
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 9)
	{
		position = position - 4;
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 10)
	{
		play[person - 1].setbal(play[person - 1].getbal() - 100);
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 11)
	{
		play[person - 1].setbal(play[person - 1].getbal() - 25);
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 12)
	{
		play[person - 1].setbal(play[person - 1].getbal() - 75);
		for (int i = 0; i < 4; i++)
		{
			if (i + 1 == person)
			{
				i++;
			}
			else
				play[i].setbal(play[i].getbal() + 25);
		}
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 13)
	{
		play[person - 1].setbal(play[person - 1].getbal() + 150);
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 14)
	{
		cout << chance[v1].getcommand() << endl;
	}
	else if (chance[v1].getnum() == 15)
	{
		position = 5;
		cout << chance[v1].getcommand() << endl;
	}
}
void Game::CommunityChest(int& position, int person)
{
	if (chancecheck == 1)
	{
		position = 0;
		cout << "Advance to GO and Collect 400 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 500);
	}
	else if (chancecheck == 2)
	{
		cout << "Bank will pay you 200 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 200);
	}
	else if (chancecheck == 3)
	{
		cout << "Pay Doctor Fee 200 PKR" << endl;

		play[person - 1].setbal(play[person - 1].getbal() - 200);
	}

	else if (chancecheck == 4)
	{
		cout << "From Sale you GOt 50 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 50);
	}
	else if (chancecheck == 5)
	{
		cout << "Get out of Jail. May be kept until needed." << endl;
		play[person - 1].setJailcard(1);
	}
	else if (chancecheck == 6)
	{
		cout << "Income Tax refund collect 150 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 150);

	}
	else if (chancecheck == 7)
	{
		cout << "Your health insurance matures collect 200 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 200);
	}
	else if (chancecheck == 8)
	{
		cout << "Pay donation to Hospital 100 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() - 100);
	}
	else if (chancecheck == 9)
	{
		cout << "Pay Student Tax of 200 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() - 200);
	}
	else if (chancecheck == 10)
	{
		cout << "Collect 50 PKR for your services." << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 50);
	}
	else if (chancecheck == 11)
	{
		cout << "Pay Street repair charges 50 PKR per House 125 PKR per Hotel." << endl;
		play[person - 1].setbal(play[person - 1].getbal() - 200);
	}
	else if (chancecheck == 12)
	{
		cout << "You won prize money of 300 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() + 300);
	}
	else if (chancecheck == 13)
	{
		cout << "Pay water bill of 50 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() - 50);
	}
	else if (chancecheck == 14)
	{
		cout << "Pay electricity bill of 80 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() - 80);
	}
	else if (chancecheck == 15)
	{
		cout << "Pay internet bill 50 PKR" << endl;
		play[person - 1].setbal(play[person - 1].getbal() - 50);
	}
	chancecheck++;
	if (chancecheck > 15)
	{
		chancecheck = 0;
	}
}
void Game::PropertyTax(int plr)
{
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;

	for (int i = 0; i < 28; i++)
	{
		if (p[i].get_own() == plr)
		{
			sum1 = sum1 + p[i].get_cost();
			if (p[i].get_houses() > 0 && p[i].get_houses() < 4)
			{
				sum2 = sum2 + ((p[i].get_houses()) * 100);
			}
			else if (p[i].get_houses() > 0 && p[i].get_houses() == 4)
			{
				sum3 = sum3 + 400;
			}
			else if (p[i].get_houses() > 0 && p[i].get_houses() == 5)
			{
				sum4 = sum4 + 500;
			}
		}
	}

	cout << "Player " << plr << " Have to give Property Tax : " << ((sum1 * 0.1) + (sum2 * 0.2) + (sum3 * 0.3) + (sum4 * 0.3)) << endl;
	play[plr - 1].setbal(play[plr - 1].getbal() - (sum1 * 0.1) - (sum2 * 0.2) - (sum3 * 0.3) - (sum4 * 0.3));
	cout << "Player " << plr << " Remaining Balance: " << play[plr - 1].getbal() << endl;
}
void Game::win(int& x)
{
	if (play[0].getbk() == 1 && play[1].getbk() == 1 && play[2].getbk() == 1)
	{
		cout << "player 4 wins" << endl;
		x = 1;
	}
	else if (play[0].getbk() == 1 && play[1].getbk() == 1 && play[3].getbk() == 1)
	{
		cout << "player 3 wins" << endl;
		x = 1;
	}
	else if (play[0].getbk() == 1 && play[3].getbk() == 1 && play[2].getbk() == 1)
	{
		cout << "player 2 wins" << endl;
		x = 1;
	}
	else if (play[3].getbk() == 1 && play[1].getbk() == 1 && play[2].getbk() == 1)
	{
		cout << "player 1 wins" << endl;
		x = 1;
	}


}
void Game::mortcheck(int Playercheck, int& selector, sf::Window& window)
{
	int i = 0;
	int j = 0;
	int bx = 0;
	cout << "Do you want to mortgage any property?" << endl;
	cout << "Press Y For Yes " << endl;
	cout << "Press N For No" << endl;
	while (window.isOpen() && bx == 0)
	{
		sf::Event eve;
		while (window.pollEvent(eve))
		{
			switch (eve.key.code)
			{

			case sf::Keyboard::Y:
				if (bx == 0)
				{
					cout << "Which property you want to mortgage or unmortgage" << endl;
					//int i = 0;
					cin >> i;
					//int j = 0;
					for (; j < 28; j++)
					{
						if (i == p[j].get_pid())
						{
							p[j].mortgage(Playercheck, play[Playercheck - 1].getbal());
							selector = 0;
							bx = 1;
						}
					}
					cout << endl;
					cout << endl;
					cout << endl;
					cout << endl;
					bx = 1;
				}

				break;
			case sf::Keyboard::N:
				cout << "OK" << endl;
				selector = 0;
				bx = 2;
				break;
			}
		}
	}


}
void Game::Graphic()
{
	int Buying = 0;
	int selector = 0;
	int Playercheck = 0;
	int positioncheck = 0;
	srand(time(NULL));
	int checkrandom = 0;
	int check = 0;
	int v1, v2, v3, v4, x = 0, y = 0, z = 0;
	int flag = 0;
	int Playermove = 1;
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0;

	ifstream fin;
	fin.open("Properties.txt", ios::app);
	if (fin)
	{
		for (int i = 0; i < 28; i++)
		{
			fin >> p[i];
		}
	}
	fin.close();

	fin.open("Chest.txt", ios::app);
	if (fin)
	{
		for (int i = 0; i < 6; i++)
		{
			fin >> c[i];
		}
	}
	fin.close();

	sf::RenderWindow window(sf::VideoMode(720, 720), "MONOPOLY");
	sf::Texture texture;
	sf::SoundBuffer buffer;

	buffer.loadFromFile("Coffin.wav");
	sf::Sound sound(buffer);

	texture.loadFromFile("monoply.jpg");
	sf::Texture saad;
	saad.loadFromFile("saad.png");
	sf::Texture abd;
	sf::Texture usama;
	sf::Texture dua;
	sf::Texture cofin;
	sf::Texture d1;
	sf::Texture d2;
	sf::Texture d3;
	sf::Texture d4;
	sf::Texture d5;
	sf::Texture d6;
	abd.loadFromFile("abd.png");
	usama.loadFromFile("usama.png");
	dua.loadFromFile("dua.png");
	d1.loadFromFile("d1.png");
	d2.loadFromFile("d2.png");
	d3.loadFromFile("d3.png");
	d4.loadFromFile("d4.png");
	d5.loadFromFile("d5.png");
	d6.loadFromFile("d6.png");
	sf::Sprite ds1;
	sf::Sprite ds2;
	sf::Sprite ds3;
	sf::Sprite ds4;
	sf::Sprite ds5;
	sf::Sprite ds6;
	sf::Sprite abdullahsprite;
	sf::Sprite usamasprite;
	sf::Sprite duasprite;
	sf::SoundBuffer Jail;
	ds1.setTexture(d1);
	ds2.setTexture(d2);
	ds3.setTexture(d3);
	ds4.setTexture(d4);
	ds5.setTexture(d5);
	ds6.setTexture(d6);
	ds1.setPosition(250, 480);
	ds2.setPosition(2000, 2000);
	ds3.setPosition(2000, 2000);
	ds4.setPosition(2000, 2000);
	ds5.setPosition(2000, 2000);
	ds6.setPosition(2000, 2000);
	Jail.loadFromFile("Ghori.wav");
	sf::Sound Jailsound(Jail);
	abdullahsprite.setPosition(35, 0);
	duasprite.setPosition(9, 35);
	usamasprite.setPosition(40, 40);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Sprite saadsprite;
	saadsprite.setTexture(saad);
	abdullahsprite.setTexture(abd);
	usamasprite.setTexture(usama);
	duasprite.setTexture(dua);

	while (window.isOpen())
	{
		int mortgagecheck = 0;
		int Upgradecheck = 0;
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::M:

					system("cls");

					if (Playermove > 4)
					{
						Playermove = 1;
					}
					if (play[Playermove - 1].getJail() == 1)
					{
						int sJail;
						if (play[Playermove - 1].getcard() == 1)
						{
							cout << "Congratulations you have a JailCard you can get out of Jail for free" << endl;
							play[Playermove - 1].setJailcard(0);
							play[Playermove - 1].setJail(0);
							Jailsound.play();
						}
						else if (play[Playermove - 1].getcard() == 0)
						{
							cout << "Press 1 on console and Pay 400 to get out" << endl;
							cout << "Press 2 on console to skip" << endl;
							cin >> sJail;
							if (sJail == 1)
							{
								play[Playermove - 1].setbal(play[Playermove - 1].getbal() - 400);
								play[Playermove - 1].setJail(0);
								Jailsound.play();
							}
							else if (sJail == 2)
							{
								Playermove++;
							}
						}
					}
					if (Playermove == 1 && play[Playermove - 1].getJail() == 0 && play[Playermove - 1].getbk() == 0)
					{
						cout << " Player 1 turn " << endl;
						v1 = (rand() % 6) + 1;
						cout << "DICE:  " << v1 << endl;
						r1 = r1 + v1;

						if (r1 > 39)
						{
							r1 = 0;
							r1 = r1 + v1;
							cout << "O Balaey! Player 1 have recieved 2000 Rs" << endl;
							play[0].setbal(play[0].getbal() + 2000);

						}
						cout << "R: " << r1 << endl;
						if (v1 == 1)
						{
							ds1.setPosition(250, 480);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds1);
						}
						else if (v1 == 2)
						{
							ds2.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds2);
						}
						else if (v1 == 3)
						{
							ds3.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds3);
						}
						else if (v1 == 4)
						{
							ds4.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds4);
						}
						else if (v1 == 5)
						{
							ds5.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds5);
						}
						else if (v1 == 6)
						{
							ds6.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							window.draw(ds6);
						}
						window.draw(sprite);
						window.draw(saadsprite);
						window.draw(abdullahsprite);
						window.draw(duasprite);
						window.draw(usamasprite);
						window.display();
						for (; y < 6; y++)
						{
							if (r1 == c[y].get_cid())
							{
								cout << "Property id" << c[y].get_cid() << endl;
								saadsprite.setPosition(c[y].get_cx(), c[y].get_cy());
								cout << "type: " << c[y].get_ctype() << endl;
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();
								_sleep(1000);
								if (c[y].get_ctype() == 2)
								{
									Chances(r1, Playermove);
								}
								else if (c[y].get_ctype() == 1)
								{
									CommunityChest(r1, Playermove);
								}
							}
						}
						if (r1 == 0)
						{
							cout << "START id: " << 0 << endl;
							saadsprite.setPosition(start.get_GOx(), start.get_GOy());
						}
						if (r1 == 20)
						{
							cout << "Free Parking id: " << 0 << endl;
							saadsprite.setPosition(fp.get_px(), fp.get_py());
							play[Playermove - 1].setbal(play[Playermove - 1].getbal() - 10);
						}
						if (r1 == 4)
						{
							cout << "Land Tax: " << 4 << endl;
							saadsprite.setPosition(lTax.get_tx(), lTax.get_ty());
							LandTax(Playermove);
						}
						if (r1 == 38)
						{
							cout << "Property Tax: " << 38 << endl;
							saadsprite.setPosition(pTax.get_tx(), lTax.get_ty());
						}
						for (; x < 28; x++)
						{
							if (r1 == p[x].get_pid())
							{
								cout << "Property id: " << p[x].get_pid() << endl;
								cout << "Property cost: " << p[x].get_cost() << endl;
								saadsprite.setPosition(p[x].get_x(), p[x].get_y());
								Playercheck = Playermove;
								positioncheck = x;
								Buying = 1;
								selector = 1;
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();

							}
						}
						x = 0;
						for (; z < 2; z++)
						{
							if (r1 == j[z].get_jid())
							{
								cout << "Jail id: " << j[z].get_jid() << endl;
								saadsprite.setPosition(j[z].get_jx(), j[z].get_jy());
								if (j[z].get_jid() == 30)
								{
									r1 = j[0].get_jid();
									saadsprite.setPosition(j[1].get_jx(), j[1].get_jy());
									window.draw(sprite);

									window.draw(saadsprite);
									window.display();

									sound.play();
									cout << "GO to Jail" << endl;
									_sleep(1000);
									saadsprite.setPosition(630, 50);
									play[Playermove - 1].setJail(1);

								}
							}
						}
						if (p[positioncheck].get_own() == Playercheck)
						{
							cout << "Total Housed owned on this property: " << p[positioncheck].get_houses() << endl;
						}
						z = 0;
						x = 0;
						y = 0;
						Playermove++;
						break;
					}
					else if (play[Playermove - 1].getbk() == 1)
					{
						Playermove++;
					}
					else if (Playermove == 2 && play[Playermove - 1].getJail() == 0 && play[Playermove - 1].getbk() == 0)
					{
						cout << " Player 2 turn " << endl;
						v2 = (rand() % 6) + 1;
						cout << "DICE:  " << v2 << endl;
						r2 = r2 + v2;

						if (r2 > 39)
						{
							r2 = 0;
							r2 = r2 + v2;
							cout << "O Balaey! Player 2 have recieved 2000 Rs" << endl;
							play[1].setbal(play[1].getbal() + 2000);
						}
						cout << "R: " << r2 << endl;
						if (v2 == 1)
						{
							ds1.setPosition(250, 480);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds1);
						}
						else if (v2 == 2)
						{
							ds2.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds2);
						}
						else if (v2 == 3)
						{
							ds3.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds3);
						}
						else if (v2 == 4)
						{
							ds4.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds4);
						}
						else if (v2 == 5)
						{
							ds5.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds5);
						}
						else if (v2 == 6)
						{
							ds6.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							window.draw(ds6);
						}
						window.draw(sprite);
						window.draw(saadsprite);
						window.draw(abdullahsprite);
						window.draw(duasprite);
						window.draw(usamasprite);
						window.display();
						for (; y < 6; y++)
						{
							if (r2 == c[y].get_cid())
							{
								cout << "Property id" << c[y].get_cid() << endl;
								abdullahsprite.setPosition(c[y].get_cx(), c[y].get_cy());
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();
								_sleep(1000);
								if (c[y].get_ctype() == 2)
								{
									Chances(r2, Playermove);
								}
								else if (c[y].get_ctype() == 1)
								{
									CommunityChest(r2, Playermove);
								}
							}
						}
						if (r2 == 0)
						{
							cout << "START id: " << 0 << endl;
							abdullahsprite.setPosition(start.get_GOx(), start.get_GOy());
						}
						if (r2 == 20)
						{
							cout << "Free Parking id: " << 0 << endl;
							abdullahsprite.setPosition(fp.get_px(), fp.get_py());
							play[Playermove - 1].setbal(play[Playermove - 1].getbal() - 10);
						}
						if (r2 == 4)
						{
							cout << "Land Tax: " << 4 << endl;
							abdullahsprite.setPosition(lTax.get_tx(), lTax.get_ty());
							LandTax(Playermove);
						}
						if (r2 == 38)
						{
							cout << "Property Tax: " << 38 << endl;
							abdullahsprite.setPosition(pTax.get_tx(), lTax.get_ty());
						}
						for (; x < 28; x++)
						{
							if (r2 == p[x].get_pid())
							{
								cout << "Property id: " << p[x].get_pid() << endl;
								cout << "Property cost: " << p[x].get_cost() << endl;
								abdullahsprite.setPosition(p[x].get_x(), p[x].get_y());

								Playercheck = Playermove;
								positioncheck = x;
								Buying = 1;
								selector = 1;
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();

							}
						}
						x = 0;
						for (; z < 2; z++)
						{
							if (r2 == j[z].get_jid())
							{
								cout << "Jail id: " << j[z].get_jid() << endl;
								abdullahsprite.setPosition(j[z].get_jx(), j[z].get_jy());

								if (j[z].get_jid() == 30)
								{
									r2 = j[0].get_jid();
									abdullahsprite.setPosition(j[1].get_jx(), j[1].get_jy());
									window.draw(sprite);

									window.draw(abdullahsprite);
									window.display();

									sound.play();
									cout << "Jail" << endl;
									_sleep(1000);
									abdullahsprite.setPosition(630, 50);
									play[Playermove - 1].setJail(1);
								}
							}

						}
						z = 0;
						x = 0;
						y = 0;
						Playermove++;
						if (p[positioncheck].get_own() == Playercheck)
						{
							cout << "Total Housed owned on this property: " << p[positioncheck].get_houses() << endl;
						}
						break;
					}
					else if (play[Playermove - 1].getbk() == 1)
					{
						Playermove++;
					}
					else if (Playermove == 3 && play[Playermove - 1].getJail() == 0 && play[Playermove - 1].getbk() == 0)
					{
						cout << " Player 3 turn " << endl;
						v3 = (rand() % 6) + 1;
						cout << "DICE:  " << v3 << endl;
						r3 = r3 + v3;
						if (v3 == 1)
						{
							ds1.setPosition(250, 480);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds1);
						}
						else if (v3 == 2)
						{
							ds2.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds2);
						}
						else if (v3 == 3)
						{
							ds3.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds3);
						}
						else if (v3 == 4)
						{
							ds4.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds4);
						}
						else if (v3 == 5)
						{
							ds5.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds5);
						}
						else if (v3 == 6)
						{
							ds6.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							window.draw(ds6);
						}
						window.draw(sprite);
						window.draw(saadsprite);
						window.draw(abdullahsprite);
						window.draw(duasprite);
						window.draw(usamasprite);
						window.display();
						for (; y < 6; y++)
						{
							if (r3 == c[y].get_cid())
							{
								cout << "Property id" << c[y].get_cid() << endl;
								usamasprite.setPosition(c[y].get_cx(), c[y].get_cy());
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();
								_sleep(1000);
								if (c[y].get_ctype() == 2)
								{
									Chances(r3, Playermove);
								}
								else if (c[y].get_ctype() == 1)
								{
									CommunityChest(r3, Playermove);
								}
							}
						}
						if (r3 == 0)
						{
							cout << "START id: " << 0 << endl;
							usamasprite.setPosition(start.get_GOx(), start.get_GOy());
						}
						if (r3 == 20)
						{
							cout << "Free Parking id: " << 0 << endl;
							usamasprite.setPosition(fp.get_px(), fp.get_py());
							play[Playermove - 1].setbal(play[Playermove - 1].getbal() - 10);
						}
						if (r3 == 4)
						{
							cout << "Land Tax: " << 4 << endl;
							usamasprite.setPosition(lTax.get_tx(), lTax.get_ty());
							LandTax(Playermove);
						}
						if (r3 == 38)
						{
							cout << "Property Tax: " << 38 << endl;
							usamasprite.setPosition(pTax.get_tx(), lTax.get_ty());
						}
						for (; x < 28; x++)
						{
							if (r3 == p[x].get_pid())
							{
								cout << "Property id: " << p[x].get_pid() << endl;
								cout << "Property cost: " << p[x].get_cost() << endl;
								usamasprite.setPosition(p[x].get_x(), p[x].get_y());
								Playercheck = Playermove;
								positioncheck = x;
								Buying = 1;
								selector = 1;
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();
							}
						}
						x = 0;
						for (; z < 2; z++)
						{
							if (r3 == j[z].get_jid())
							{
								cout << "Jail id: " << j[z].get_jid() << endl;
								usamasprite.setPosition(j[z].get_jx(), j[z].get_jy());

								if (j[z].get_jid() == 30)
								{

									r3 = j[0].get_jid();
									usamasprite.setPosition(j[1].get_jx(), j[1].get_jy());
									window.draw(sprite);

									window.draw(usamasprite);
									window.display();

									sound.play();
									cout << "Jail" << endl;

									_sleep(1000);
									usamasprite.setPosition(630, 50);
									play[Playermove - 1].setJail(1);

								}
							}
						}
						z = 0;
						x = 0;
						y = 0;
						Playermove++;
						if (p[positioncheck].get_own() == Playercheck)
						{
							cout << "Total Housed owned on this property: " << p[positioncheck].get_houses() << endl;
						}
						break;
					}
					else if (play[Playermove - 1].getbk() == 1)
					{
						Playermove++;
					}
					else if (Playermove == 4 && play[Playermove - 1].getJail() == 0 && play[Playermove - 1].getbk() == 0)
					{
						cout << " Player 4 turn " << endl;
						v4 = (rand() % 6) + 1;
						cout << "DICE:  " << v4 << endl;
						r4 = r4 + v4;

						if (r4 > 39)
						{
							r4 = 0;
							r4 = r4 + v4;
							cout << "O Balaey! Player 4 have recieved 2000 Rs" << endl;
							play[3].setbal(play[3].getbal() + 2000);
						}
						cout << "R: " << r4 << endl;
						if (v4 == 1)
						{
							ds1.setPosition(250, 480);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds1);
						}
						else if (v4 == 2)
						{
							ds2.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds2);
						}
						else if (v4 == 3)
						{
							ds3.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds3);
						}
						else if (v4 == 4)
						{
							ds4.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds4);
						}
						else if (v4 == 5)
						{
							ds5.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds6.setPosition(2000, 2000);
							window.draw(ds5);
						}
						else if (v4 == 6)
						{
							ds6.setPosition(250, 480);
							ds1.setPosition(2000, 2000);
							ds2.setPosition(2000, 2000);
							ds3.setPosition(2000, 2000);
							ds4.setPosition(2000, 2000);
							ds5.setPosition(2000, 2000);
							window.draw(ds6);
						}
						window.draw(sprite);
						window.draw(saadsprite);
						window.draw(abdullahsprite);
						window.draw(duasprite);
						window.draw(usamasprite);
						window.display();
						for (; y < 6; y++)
						{
							if (r4 == c[y].get_cid())
							{
								cout << "Property id" << c[y].get_cid() << endl;
								duasprite.setPosition(c[y].get_cx(), c[y].get_cy());
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();
								_sleep(1000);
								if (c[y].get_ctype() == 2)
								{
									Chances(r4, Playermove);
								}
								else if (c[y].get_ctype() == 1)
								{
									CommunityChest(r4, Playermove);
								}
							}
						}
						if (r4 == 0)
						{
							cout << "START id: " << 0 << endl;
							duasprite.setPosition(start.get_GOx(), start.get_GOy());
						}
						if (r4 == 20)
						{
							cout << "Free Parking Pay RS 10" << endl;
							duasprite.setPosition(fp.get_px(), fp.get_py());
							play[Playermove - 1].setbal(play[Playermove - 1].getbal() - 10);
						}
						if (r4 == 4)
						{
							cout << "Land Tax: " << 4 << endl;
							duasprite.setPosition(lTax.get_tx(), lTax.get_ty());
							LandTax(Playermove);
						}
						if (r4 == 38)
						{
							cout << "Property Tax: " << 38 << endl;
							duasprite.setPosition(pTax.get_tx(), lTax.get_ty());
						}
						for (; x < 28; x++)
						{
							if (r4 == p[x].get_pid())
							{
								cout << "Property id: " << p[x].get_pid() << endl;
								cout << "Property cost: " << p[x].get_cost() << endl;
								duasprite.setPosition(p[x].get_x(), p[x].get_y());
								Playercheck = Playermove;
								positioncheck = x;
								Buying = 1;
								selector = 1;
								window.draw(sprite);
								window.draw(saadsprite);
								window.draw(abdullahsprite);
								window.draw(duasprite);
								window.draw(usamasprite);
								window.display();
							}
						}
						x = 0;
						for (; z < 2; z++)
						{
							if (r4 == j[z].get_jid())
							{
								cout << "Jail id: " << j[z].get_jid() << endl;
								duasprite.setPosition(j[z].get_jx(), j[z].get_jy());

								if (j[z].get_jid() == 30)
								{

									r4 = j[0].get_jid();
									duasprite.setPosition(j[1].get_jx(), j[1].get_jy());
									window.draw(sprite);

									window.draw(duasprite);
									window.display();

									sound.play();
									cout << "Jail" << endl;

									_sleep(5000);
									duasprite.setPosition(630, 50);
									play[Playermove - 1].setJail(1);
								}
							}
						}
						z = 0;
						x = 0;
						y = 0;
						Playermove++;
						if (p[positioncheck].get_own() == Playercheck)
						{
							cout << "Total Housed owned on this property: " << p[positioncheck].get_houses() << endl;
						}
						break;
					}

				}
			}
			window.draw(sprite);
			window.draw(saadsprite);
			window.draw(abdullahsprite);
			window.draw(duasprite);
			window.draw(usamasprite);
			window.draw(ds1);
			window.draw(ds2);
			window.draw(ds3);
			window.draw(ds4);
			window.draw(ds5);
			window.draw(ds6);
			window.display();
		}
		if (selector == 1)
		{
			mortcheck(Playercheck, selector, window);
		}
		if (Buying == 1)
		{
			Buy(positioncheck, Playercheck, window, Upgradecheck);
			Buying = 0;
		}
		if (play[Playercheck - 1].getbal() < p[positioncheck].get_cost() && positioncheck > 0 && positioncheck < 28)
		{
			//nazuk.play();
		}
		if (Upgradecheck == 1)
		{
			cout << "Entered Upgrade" << endl;
			Upgrade(positioncheck, Playercheck, window);
			Upgradecheck = 0;

		}
		if (Upgradecheck == 2)
		{
			cout << "Building Entered" << endl;
			Build(positioncheck, Playercheck, window);
		}
		if (play[Playercheck - 1].getbal() < 1)
		{
			play[Playercheck - 1].setbk(1);
		}
		int winner;
		win(winner);
		selector = 0;
		if (winner == 1)
		{
			window.close();
		}
	}

}

