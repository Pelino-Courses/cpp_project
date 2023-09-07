#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class shopping 
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
        int paymentOption;
		public:
			void menu();
			void administrator();
			void buyer();
			void edit();
			void rem();
			void add();
			void list();
			void listt();
            void pay();
			void receipt(int productCode, int quantity);
};

void shopping::menu()
{
	m:
	int choice;
	string email;
	string password;
	
	
	cout<<"\t\t\t\t_________________________________________\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t       Virtual Shop Assistant            \n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t       Ikaze Muri Chez Carine            \n";
	cout<<"\t\t\t\t_________________________________________\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t| 1) Administrator   |\n";
	cout<<"\t\t\t\t|                    |\n";
	cout<<"\t\t\t\t| 2) Buyer           |\n";
	cout<<"\t\t\t\t|                    |\n";
	cout<<"\t\t\t\t| 3) Exit            |\n";
	cout<<"\t\t\t\t|                    |\n";
	cout<<"\n\t\t\t  Please Enter any choice:\t";
	cin>>choice;
	
	switch(choice)
	{
	  case 1:
	    {
	    	cout<<"\t\t\tPlease Login";
            cout<<"\t\t\t Enter Email:\t";
        	cin>>email;
	        cout<<"\t\t\t Enter Password:\t";
        	cin>>password;
	
        	if((email=="nijeanfelix@gmail.com" && password=="freefelix") || (email == "isumbabyosed@gmail.com" && password=="Depha"))
        	{
	        	administrator();
        	}
        	else
        	{
	        	cout<<"Invalid Email/Password";
	       }
		   break;
		};    
    	   	
	 case 2:
	       {
	       	 buyer();
	       	 break;
		   }
	  case 3:
	       {
	       	 exit(0);
		   }
	  default:
	       {
	       	cout<<" Please select from the given above.";
	}	   }
goto m;		
}


void shopping::administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator Menu\n";
	cout<<"\n\t\t\t|____1) Add the product_______|";
	cout<<"\n\t\t\t|                             |";
	cout<<"\n\t\t\t|____2) Modify the product____|";
	cout<<"\n\t\t\t|                             |";
	cout<<"\n\t\t\t|____3) Delete the product____|";
	cout<<"\n\t\t\t|                             |";
	cout<<"\n\t\t\t|____4) Back to Main Menu_____|";
	cout<<"\n\t\t\t|                             |";
	cout<<"\n\t\t\t|____5) Available product_____|";
	 
	cout<<"\n\n\t Please enter the choice:\t";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			{
			    add();
			    break;	
			}
		case 2:
			{
				edit();
				break;
			}
		case 3:
			{
				rem();
				break;
			}
		case 4:
			{
				menu();
				break;
			}
		case 5:
			{
				listt();
				break;
			}
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}

void shopping::receipt(int productCode, int quantity)
{
    fstream data;
    float total = 0;

    data.open("Database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty Database";
        return;
    }

    int code;
    string name;
    float price, discount;

    while (data >> code >> name >> price >> discount)
    {
        if (productCode == code)
        {
            cout << "\n ___________________________\n";
            cout << "\n|                           |\n";
            cout << "\n| Receipt Details for       |\n";
            cout << "\n| Product Code: " << productCode << "           |\n";
            cout << "\n|                           |\n";
            cout << "\n|___________________________|\n";

            cout << "\nProduct Name: " << name << "\n";
            cout << "Quantity: " << quantity << "\n";
            cout << "Price per unit: " << price << "\n";

            float amount = price * quantity;
            float dis = amount - ((amount * discount) / 100);

            cout << "Total Price: " << amount << "\n";
            cout << "Price with Discount: " << dis << "\n";

            total += dis;
        }
    }

    data.close();

    if (total > 0)
    {
        cout << "\n\n___________________________________________";
        cout << "\n Total Amount: " << total << "\n \n";
        pay();
    }
    else
    {
        cout << "\nProduct with code " << productCode << " not found.\n";
    }
}



void shopping::buyer()
{
    m:
    int choice;
    cout << "\t\t\t  Buyer \n";
    cout << "\t\t\t--------------\n";
    cout << "\t\t\t              \n";
    cout << "\t\t\t 1) Buy Product\n";
    cout << "\t\t\t              \n";
    cout << "\t\t\t 2) Go back   \n";
    cout << "\t\t\t              \n";
    cout << "\t\t\t Enter your choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        listt(); // Show the list of available products

        char addAnother;
        do
        {
            int productCode;
            int quantity;
             cout << "\n";
              cout << "\n";
            cout << "Enter the product code: ";
            cin >> productCode;

            // Check if the entered product code is valid
            bool validProduct = false;
            fstream data("Database.txt", ios::in);
            if (data)
            {
                int code;
                string name;
                float price, discount;
                while (data >> code >> name >> price >> discount)
                {
                    if (productCode == code)
                    {
                        validProduct = true;
                        break;
                    }
                }
                data.close();
            }

            if (validProduct)
            {
                cout << "Enter the quantity: ";
                cin >> quantity;

                // Call the receipt function with the chosen product code and quantity
                receipt(productCode, quantity);
            }
            else
            {
                cout << "Invalid product code. Please try again.\n";
            }

            cout << "Add another product? (y/n): ";
            cin >> addAnother;
        } while (addAnother == 'y' || addAnother == 'Y');
        break;
    case 2:
        menu(); // Go back to the main menu
        break;
    default:
        cout << "Invalid choice!";
    }

    goto m;
}



void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    char choice;

    do
    {
        cout << "\n\n\t\t\t Add new product";
        cout << "\n\n\t Product code of the product:";
        cin >> pcode;
        cout << "\n\n\t Name of the Product \t";
        cin >> pname;
        cout << "\n\n\t Price of product \t";
        cin >> price;
        cout << "\n\n\t Discount on Product \t";
        cin >> dis;

        data.open("Database.txt", ios::in);
        if (!data)
        {
            data.open("Database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
        else
        {
            data >> c >> n >> p >> d;
            while (!data.eof())
            {
                if (c == pcode)
                {
                    token++;
                }
                data >> c >> n >> p >> d;
            }
            data.close();

            if (token == 1)
            {
                cout << "\n\n\t\t Record with the same product code already exists!";
            }
            else
            {
                data.open("Database.txt", ios::app | ios::out);
                data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                data.close();
                cout << "\n\n\t\t Record inserted!";
            }
        }

        listt(); // Print the list of available records

        cout << "\n\nDo you want to add another record? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void shopping::listt()
{
    fstream data;
    data.open("Database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n File does not exist or cannot be opened.";
        return;
    }



    cout << "\n\n______________________________________________________________";
    cout << "\nProduct Code \t Product Name \t Price \t Discount";
    cout << "\n______________________________________________________________";

    while (data >> pcode >> pname >> price >> dis)
    {
        cout << "\n" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << dis;
    }

    data.close();
}

void shopping::pay()
{
    cout << "\nPayment Options:\n";
    cout << "1) MTN Mobile Money\n";
    cout << "2) Airtel Money\n";
    // Add other payment options...

    cout << "Select a payment option: ";
    cin >> paymentOption;

    // Validate payment option
    if (paymentOption < 1 || paymentOption > 2 /* Add more conditions for other options */)
    {
        cout << "Invalid payment option selected." << endl;
        return;
    }

    // Payment validation and processing logic for each option
    switch (paymentOption)
    {
        case 1:
            {
                string mobileMoneyAccount;
                string mobileMoneyPIN;

                // Prompt the user for MTN Mobile Money account number and PIN
                cout << "Enter MTN Mobile Money Account Number: ";
                cin >> mobileMoneyAccount;
                cout << "Enter MTN Mobile Money PIN: ";
                cin >> mobileMoneyPIN;

                // Perform validation (e.g., check if the account and PIN are valid)

                // Process the payment (e.g., deduct the amount from the account)
                // Update the payment status or send a payment confirmation

                cout << "Payment completed using MTN Mobile Money." << endl;
                break;
            }

        case 2:
            {
                string airtelMoneyAccount;
                string airtelMoneyPIN;

                // Prompt the user for Airtel Money account number and PIN
                cout << "Enter Airtel Money Account Number: ";
                cin >> airtelMoneyAccount;
                cout << "Enter Airtel Money PIN: ";
                cin >> airtelMoneyPIN;

                // Perform validation (e.g., check if the account and PIN are valid)

                // Process the payment (e.g., deduct the amount from the account)
                // Update the payment status or send a payment confirmation

                cout << "Payment completed using Airtel Money." << endl;
                break;
            }

        // Add cases for other payment options...

        default:
            cout << "Invalid payment option selected." << endl;
    }    
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    
    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> pkey; // Input the product code
    
    data.open("Database.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t File does not exist!";
        return;
    }
    
    data1.open("Database1.txt", ios::app | ios::out);
    
    // Read data from the input file and process it
    while (data >> pcode >> pname >> price >> dis)
    {
        if (pkey == pcode)
        {
//            cout << "\n\t\t Product new code :";
//            cin >> c; // Input the new product code
            cout << "\n\t\t new Name of the product :";
            cin >> n; // Input the new product name
            cout << "\n\t\t new Price: ";
            cin >> p; // Input the new product price
            cout << "\n\t\t Discount: ";
            cin >> d; // Input the new product discount
            
            // Write the updated product information to the output file
            data1 << " " << c << " " << n << " " << p << " " << d << "\n";
            
            cout << "\n\t\t Record edited";
            token++;
        }
        else
        {
            // Write the existing product information to the output file
            data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
    }
    
    data.close();
    data1.close();
    
    // Remove the old database file and rename the new one to replace it
    remove("Database.txt");
    rename("Database1.txt", "Database.txt");
    
    if (token == 0)
    {
        cout << "Record not found!";
    }
}



void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete Product?";
	cout<<"\n\n\t Please!!!Enter product code:";
	cin>>pkey;
	data.open("Database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesn't Exit";
	}
	else
	{
		data1.open("Database1.txt",ios::app | ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
	       if(pcode==pkey)
		    {
			 cout<<"\n\n\t Product deleted successfull";
			 token++;
		    } 
	     	else
	    	{
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		    }
	    	data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("Database.txt");
		rename("Database1.txt","Database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found!";
		}
	}
}


void shopping::list()
{
	fstream data;
	data.open("Database.txt",ios::in);
	cout<<"\n\n_________________________________________";
	cout<<"ProNo \t\t ProName \t\t Price \t\t Discount";
	cout<<"\n\n__________________________________________";
	data>>pcode>>pname>>price>>dis;
	
	while(!data.eof())
	{
	
		data<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
		data>>pcode>>pname>>price>>dis;
		
	}
	data.close();
}
int main(int argc, char** argv) 
{ 
	shopping s;
 	s.menu();
	
	return 0;
}
