 
#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
#include <queue>
#include <stack>

using namespace std;

class clsQueueLine
{
private:

	string _Prefix = "";
	short _TotalTickets;
	short _AverageServeClient = 0;

	class clsTicket
	{
	private:
		short _Number;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients;
		short _AverageServeTime;

	public:
		
		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_Number = Number;
			_Prefix = Prefix;
			_WaitingClients = WaitingClients;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_AverageServeTime = AverageServeTime;

		}

		short Number()
		{
			return _Number;
		}

		string Prefix()
		{
			return _Prefix;
		}

		string FullNumber()
		{
			return  _Prefix + to_string(_Number);
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short ExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void Print()
		{
			cout << "\n\t\t\t\t\     ....Ticket....";
			cout << "\n\t\t\t\t__________________________\n";

			cout << "\n\t\t\t\t\t   " << FullNumber() << endl << endl;
			cout << "\t\t\t\t " << _TicketTime << endl;
			cout << "\t\t\t\t  Waiting Clients = " << _WaitingClients << endl;
			cout << "\t\t\t\t   Serve Time In" << endl;
			cout << "\t\t\t\t   " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t\t__________________________\n";
		}


	};

public:

	clsQueueLine(string Prefix, short AverageServeClient)
	{
		_Prefix = Prefix;
		_AverageServeClient = AverageServeClient;
		_TotalTickets = 0;
	}

	queue<clsTicket> QueueLine;

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients() , _AverageServeClient);
		QueueLine.push(Ticket);

	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;
		else
			QueueLine.pop();
		return true;
	}

	short WaitingClients()
	{
		return QueueLine.size();
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			cout << "\nNo Clients Left.\n";
		else
			return QueueLine.front().FullNumber();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t\t__________________________\n";
		cout << "\n\t\t\t\t\tQueue Info\n";
		cout << "\n\t\t\t\t__________________________\n";
		cout << "\n\t\t\t\t   Prefix   = " << _Prefix << endl;
		cout << "\t\t\t\t   Total Tickets   = " << _TotalTickets << endl;
		cout << "\t\t\t\t   Served Clients  = " << ServedClients() << endl;
		cout << "\t\t\t\t   Waiting Clients = " << WaitingClients();
		cout << "\n\t\t\t\t__________________________\n";

	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())		
		    cout << "\n\t\tTickets: No Tickets.";
		else
		cout << "\n\t\t\t\tTickets: ";

		queue<clsTicket> TempQueueLine = QueueLine;



		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();

			cout << Ticket.FullNumber() << "-->";
			TempQueueLine.pop();
		}
		cout << endl;

	}

	void PrintTicketsLineLTR()
	{

		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\t\t\tTickets: ";

		queue<clsTicket> TempQueueLine = QueueLine;
		stack<clsTicket> TempStackLine;
	
		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}
	
	
		while (!TempStackLine.empty())
		{
			clsTicket Ticket = TempStackLine.top();
	
			cout << Ticket.FullNumber() << "<--";
			TempStackLine.pop();
		}
		cout << endl;
	
	
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t        ___Tickets___ ";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ___No Tickets___";
		
		queue<clsTicket> Temp = QueueLine;

		while (!Temp.empty())
		{
			Temp.front().Print();
			Temp.pop();
		}
	}

};
