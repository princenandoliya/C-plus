#include <iostream>
#include <string>
using namespace std;

class Diamond
{
	private:
	int comp_id;
	string comp_name;
	int comp_staff_quantity;
	int comp_revenue;
	int comp_import_raw_diamonds;
	int comp_export_raw_diamonds;
	string comp_ceo;	
	
	public:
	Diamond(int id,string name,int staff,int revenue,int import_diamonds,int export_diamonds, string ceo)
	{
		comp_id = id;
		comp_name = name;
		comp_staff_quantity = staff;
		comp_revenue = revenue;
		comp_import_raw_diamonds = import_diamonds;
		comp_export_raw_diamonds = export_diamonds;
		comp_ceo = ceo;
	}
	
	void displayData(int i)
	{
		cout << "\n Diamond company :"<< 1+i <<"Details---\n";
		cout << "Company ID           :" <<comp_id <<endl;
		cout << "Company Name         :" <<comp_name <<endl;
		cout << "Staff Quantity       :" <<comp_staff_quantity <<endl;
		cout << "Revenue (per years)  :"<<comp_revenue <<endl;
		cout << "Import Diamonds       :"<<comp_import_raw_diamonds <<endl;
		cout << "Export Diamonds       :"<<comp_export_raw_diamonds <<endl;
		cout << "Comp Ceo             :"<<comp_ceo <<endl; 
	}
	
	~Diamond()
	{
		cout << "Destructor Called  :" << endl;
	}
};

int main()
{
	int n;
	cout << "Enter Number of Diamond Company :";
	cin >> n;
	
	Diamond *d[n];
	
	
	for(int i = 0;i < n;i++)
	{
		int id,staff,revenue,import_diamonds,export_diamonds;
		string name,ceo;
		
		cout << "\n Enter Details of Diamond Company" << i + 1 << endl;
		
		
			 cout << "ID: ";
		cin >> id;
		cin.ignore();

		cout << "Company Name: ";
		getline(cin, name);

		cout << "Staff Quantity: ";
		cin >> staff;

		cout << "Revenue: ";
		cin >> revenue;

		cout << "Imported Raw Diamonds: ";
		cin >> import_diamonds;

		cout << "Exported Diamonds: ";
		cin >> export_diamonds;
		cin.ignore();

		cout << "CEO Name: ";
		getline(cin, ceo);
		
		
		Diamond 		
		d(id,name,staff,revenue,import_diamonds,export_diamonds,ceo);
		d.displayData(i);
	}
		
	return 0;
	
}