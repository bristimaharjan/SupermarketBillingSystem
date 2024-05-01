#include <windows.h> 
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
 
using namespace std;
 void main_menu();
class login{
    private:
        string pass;
        string name;
    public:
        void log_in();  
        void register_user();
        void forget();
}test;
void authentication ()
{
    int choice;
    login obj;

    while(true) {
    	system("COLOR F0");
    	system("cls");
    //	cout<<"***********************************************************************\n\n\n";
     //   cout<<"                      Welcome to login page                               \n\n";
        cout<<"-------------------      AUTHENTICATION   -------------------------      \n\n";
        cout << "1. LOGIN\n";
        cout << "2. REGISTER\n";
        cout << "3. FORGET\n";
        cout << "4. MAIN MENU\n";
        cout << "Enter your choice(1,2,3,4): ";

        cin >> choice;

        switch(choice) {
            case 1:
                obj.log_in();
                return;
            case 2:
                obj.register_user();
                break;
            case 3:
                obj.forget();
                break;
            case 4:
                main_menu();
                break;
				  default:
                cout << "Invalid input! Please try again." << endl;
        }
    }

}
	
void login::register_user() {
    system("cls");
    ifstream inFile("users2.txt",ios::app); // Open the file in input mode

    if (!inFile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }
    	cout<<"-------------------REGISTER ACCOUNT--------------------";
    	cout<<endl;

    cout << "Enter new user name:" << endl;
    cin >> name;

    while (inFile >> test.name >> test.pass) { // Read existing usernames
        if (test.name == name) {
            cout << "\nUsername " << test.name << " already exists!" << endl;
            Sleep(1000);
            cout << "Please choose a different username:" << endl;
            cin >> name;
            inFile.close(); // Close the file
            inFile.open("users2.txt"); // Reopen the file for further checks
        }
    }

    inFile.close(); // Close the file

    ofstream outFile("users2.txt", ios::app); // Open the file in append mode

    if (!outFile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    cout << "Enter password for new user (10 characters):" << endl;
    cin >> pass;

    while (pass.length() != 10) {
        cout << "Password must be exactly 10 characters long. Please try again:" << endl;
        cin >> pass;
    }

    outFile << name << " " << pass << endl; // Write username and password to file

    outFile.close(); // Close the file

    cout << "User registered successfully!" << endl;
    Sleep(2000);
    
}


void login::log_in(){
	system("cls");
    cout<<"-------------------LOGIN--------------------";
    cout<<endl;
    cout << "Enter user name:" << endl;
    cin >> name;
    
    cout << "Enter password:" << endl;
    cin >> pass;

    ifstream infile("users2.txt");

    if (!infile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    string username;
    string password;
    bool found = false;

    while (infile >> username >> password) {
        if (name == username && pass == password) {
            found = true;
            break;
        }
    }

    if(found){
        printf("\n\t\tLogin successful\n");
        int i;
        cout<<"\n\t\tLogging in ";
        for(i=1;i<4;i++){
        	cout<<".";
        	Sleep(1000);
		}
  }
    else
    {
        printf("\n\t\tLogin failed! Invalid username or password.\n");
        Sleep(2000);
        authentication();
    }
			
}


void login::forget() {
	system("cls");
    cout << "Enter user name:" << endl;
    cin >> name;

    ifstream infile("users2.txt");

    if (!infile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    string username;
    string password;
    bool found = false;

    while (infile >> username >> password) {
        if (name == username) {
            found = true;
            cout << "\nYour password is: " << password << endl;
            Sleep(3000);
            break;
        }
    }

    if (!found) {
        cout << "\nUser not found!" << endl;
        Sleep(2000);
    }
    
}

 
class product
{
	int product_number;
	char product_name[50];
	float product_price,product_discount;
	
	public:
		int  product_quantity;
	
 
	void create_product()
	{
		cout<<endl<<"Please Enter The Product Number: ";
		cin>>product_number;
		cout<<endl<<"Please Enter The Name of The Product: ";
		cin.ignore();
		cin.getline(product_name ,50);
		cout<<endl<<"Please Enter The Price of The Product: ";
		cin>>product_price;
		cout<<endl<<"Please Enter The Discount (%): ";
		cin>>product_discount;
		cout<<endl<<"Please Enter The Quantity : ";
		cin>>product_quantity;
	}
	
	void show_product()
	{
		cout<<endl<<"Product #: "<<product_number;
		cout<<endl<<"Product Name: "<<product_name;
		cout<<endl<<"Product Price: "<<product_price;
		cout<<endl<<"Discount : "<<product_discount;
	    cout<<endl<<"Quantity : "<<product_quantity;
	}
	int getProduct_code()
	{
		return product_number;
	}
	
	
	float getPrice()
	{
		return product_price;
	}
	
	char* getName()
	{
		return product_name;
	}
	
	float getDiscount()
	{
		return product_discount;
	}
	void update_product() {
        cout <<"Enter New Product Name: ";
        cin.ignore();
        cin.getline( product_name,50);
        cout <<"Enter New Product Price: ";
        cin >> product_price;
        cout <<"Enter New Discount (%): ";
        cin >> product_discount;
         cout <<"Enter Quantity: ";
        cin >> product_quantity;
    }
};
fstream file_obj;
product prod;
 
 
void inventory_add()
{
	// Open file for reading and writing in binary mode
	ifstream file_obj("inventory.dat", ios::binary | ios::app);
	file_obj.seekg(ios::beg);
	if (!file_obj)
	{
		cout << "File does not exist" << endl;
		Sleep(2000);
		return;
	}
	cout<<"------------------------ADD RECORDS---------------------------";
	cout<<endl;

	product new_product;
	bool add_more = true; // Flag to check if the user wants to add more products

	while (add_more)
	{
		bool already_exists = false; // Declare already_exists here
	flag:
		prod.create_product(); // Get product details from user input

		file_obj.clear(); // Clear any error flags
		while (file_obj.read((char *)&new_product, sizeof(product)))
		{
			// Compare the product name and ID
			if (strcmp(new_product.getName(), prod.getName()) == 0 || new_product.getProduct_code() == prod.getProduct_code())
			{
				already_exists = true;
				cout << endl
					 << "Product with this name or id already exists in the inventory.";
					 
				break;
			}
		}

		if (!already_exists)
		{
			ofstream file_write_obj("inventory.dat", ios::app | ios::binary);
			file_write_obj.write((char *)&prod, sizeof(product)); // Write product to file
			file_write_obj.close();
			cout << endl
				 << "The Product Has Been Successfully Created...";
		}

		cout << "\nDo you want to add more products? (y/n): ";
		char choice;
		cin >> choice;
		if (choice != 'y' && choice != 'Y')
		{
			add_more = false;
			file_obj.close();
			return;
		}
	}

	file_obj.close(); // Close the file
}
void display_product()
{
	system("cls");
	cout<<endl<<"-------------------------------------------\n";
	cout<<endl<<" INVENTORY RECORDS.";
	cout<<endl<<"--------------------------------------------\n";
	file_obj.open("inventory.dat",ios::in);
	if(!file_obj)
	{
		cout<<endl<<"File not found ";
		exit(0);
	}
	while(file_obj.read((char*)&prod,sizeof(product)))
	{
		prod.show_product();
		cout<<endl<<"\t\t--------------------------------------------\n"<<endl;

	}
	Sleep(3000);
	file_obj.close();
} 
void search_product()
{
	int num;
	bool found=false;
    ifstream file_obj("inventory.dat", ios::binary | ios::app);
	file_obj.seekg(ios::beg);
	if (!file_obj)
	{
		cout << "File does not exist" << endl;
		Sleep(2000);
		return;
	}

	cout<<"---------------------SEARCH RECORDS--------------------";
	cout<<endl;
	cout<<"Enter product code number ";
	cin>>num;
	while(file_obj.read((char*)&prod,sizeof(product)))
	{
		if(prod.getProduct_code()==num)
		{
			system("cls");
			cout<<"---------------------SEARCH RECORDS--------------------";
			prod.show_product();
			found=true;
			Sleep(2000);
		}
	}
	
	file_obj.close();
	if(found != true)
	cout<<"\n\nNo record found";
	 	Sleep(2000);
	getchar();
}

void delete_product()
{
	display_product();
	int num;
	system("cls");
	cout<<"---------------------DELETE RECORDS------------------------";
	cout<<endl;
	cout<<endl<<endl<<"Please Enter The product #: ";
	cin>>num;
	file_obj.open("inventory.dat",ios::in|ios::out);
	if(!file_obj)
	{
		cout<<endl<<"File not found ";
		exit(0);
	}
	fstream  file_obj2;
	file_obj2.open("Temp.dat",ios::out);
	if(!file_obj2)
	{
		cout<<endl<<"File not found ";
	}

    file_obj.seekg(0,ios::beg);
	while(file_obj.read((char*)&prod,sizeof(product)))
	{
		if(prod.getProduct_code()!=num)
		{
			file_obj2.write((char*)&prod,sizeof(product));
		}
	}
	file_obj2.close();
	file_obj.close();
	remove("inventory.dat");
	rename("Temp.dat","inventory.dat");
	cout<<endl<<endl<<"Record Deleted......";
	getchar();
	return;
}


void modify_product(){
	display_product();
		cout<<"-----------------------MODIFY RECORDS--------------------";
		cout<<endl;
	int product_number;
	cout<<"Enter Product Number to Modify:";
	cin>>product_number;
	fstream file("inventory.dat",ios::in | ios::out);
	
	bool found= false;
	while(file.read((char*)&prod,sizeof(prod))){
		if(prod.getProduct_code()==product_number){  
			found=true;
			cout<<"\nProduct Found. Please provide updated details:" << endl;
			 prod.update_product();
			 file.seekp(file.tellg()-sizeof(prod));
            file.write((char*)&prod, sizeof(prod));
            file.close();
            cout <<"\nProduct has been successfully updated." << endl;
			 Sleep(1000);
			 break;
		}
		
	}
	 if (!found){
	 
        cout << "Product not found with the provided number." << endl;
               }
               getchar();
               
   }
   
   void display_product_menu()
{
	system("cls");
	file_obj.open("inventory.dat",ios::in);
	if(!file_obj)
	{
		cout<<endl<<"File not found ";
		exit(0);
	}
 
	cout<<endl<<endl<<"------------Product MENU-------------\n\n";
	cout<<"------------------------------------------------------\n";
	cout<<"P.NO.|\t\tNAME|\t\tPRICE|\n";
	cout<<"-------------------------------------------------------\n";
	while(file_obj.read((char*)&prod,sizeof(product)))
	{
		cout<<prod.getProduct_code()<<"\t\t"<<prod.getName()<<"\t\t"<<prod.getPrice()<<endl;
	}
	file_obj.close();
	Sleep(2000);
}
 
   
  void update_inventory(int product_number, int quantity) {
  	
    fstream file_obj("inventory.dat", ios::in | ios::out);
    while (file_obj.read((char*)&prod, sizeof(prod))) {
        if (prod.getProduct_code() == product_number) {
            
             prod.product_quantity -= quantity;
            file_obj.seekp(file_obj.tellg() - sizeof(prod));
            file_obj.write((char*)&prod, sizeof(prod));
            break;
        }
    }
    file_obj.close();
}
bool check_inventory(int product_number, int quantity);

void add_to_cart() {
    int order_arr[50], quantity[50], i = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    display_product_menu();
    cout << "\n-----------------------------------------------------\n";
    cout << "\n\t\t ADD TO CART";
    cout << "\n-----------------------------------------------------\n";
    do {
        cout << "\n\nEnter The Product #: ";
        cin >> order_arr[i];
        cout << "\nQuantity: ";
        cin >> quantity[i];
        // Check if the requested quantity is available in the inventory
        if (!check_inventory(order_arr[i], quantity[i])) {
            cout << "Insufficient quantity in the inventory for product #" << order_arr[i] << ". Please choose a lower quantity or another product.\n";
            continue; // Continue to the next iteration of the loop
        }
        update_inventory(order_arr[i], quantity[i]);
        i++;
        cout << "\nDo You Want To ADD Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    getchar();
    system("cls");
   	cout<<"\n\n--------------------------BILL--------------------------------\n";
	cout<<"\nPr No.|\tPr Name|\tQuantity |\tPrice |\tAmount |\tAmount after discount\n";
    for (int x = 0; x < i; x++) {
        file_obj.open("inventory.dat", ios::in);
        if(!file_obj)
	{
		cout<<endl<<"File not found ";
		exit(0);
	}
        file_obj.read((char*)&prod, sizeof(product));
        while (!file_obj.eof()) {
            if (prod.getProduct_code() == order_arr[x]) {
                amt = prod.getPrice() * quantity[x];
                damt = amt - (amt * prod.getDiscount() / 100);
                cout << "\n" << order_arr[x] << "\t\t" << prod.getName() << "\t\t" << quantity[x] << "\t\t" << prod.getPrice() << "\t\t" << amt << "\t\t" << damt;
                total += damt;
            }
            file_obj.read((char*)&prod, sizeof(product));
        }
        file_obj.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    getchar();
}

bool check_inventory(int product_number, int quantity) {
    ifstream file_obj("inventory.dat");
    while (file_obj.read((char*)&prod, sizeof(prod))) {
        if (prod.getProduct_code() == product_number) {
            if (prod.product_quantity >= quantity) {
                file_obj.close();
                return true; // Sufficient quantity available in inventory
            } else {
                file_obj.close();
                return false; // Insufficient quantity available in inventory
            }
        }
    }
    file_obj.close();
    return false; // Product not found in inventory
}



void admin_menu()
{
	 
	while(1){
		system("COLOR F0");
	system("cls");
	int choice;
	char ch;
	cout<<"\t----------------ADMIN MENU---------------------------";
	cout<<"\n\t 1. CREATE PRODUCT";
	cout<<"\n\t 2. DISPLAY PRODUCT";
	cout<<"\n\t 3. SEARCH PRODUCT ";
	cout<<"\n\t 4. DELETE PRODUCT ";
	cout<<"\n\t 5. MODIFY PRODUCT";
	cout<<"\n\t 6. EXIT";
	cout<<"\n\t 7. GO BACK TO MAIN MENU";
	cout<<"\n\t-----------------------------------------";
 
	cout<<"\n\n\tChoose your option: ";
	cin>>choice;
	switch(choice)
	{
		case 1: system("cls");
				inventory_add();
				break;
				
		case 2: system("cls");
		     display_product();
		       
				break;
				
		case 3: system("cls");
				search_product();
				break;
	   case 4: system("cls");
	            delete_product();
				break;
				
	    case 5: system("cls");
	           modify_product();
	           break;
	    case 6: system("cls");
				cout<<endl<<"ARE YOU SURE YOU WANT TO EXIT(y/n) ";
				cin>>ch;
				if(ch=='y'||ch=='Y')
				{
					exit(0);
					
				}
				else{
					continue;
				}
				
		case 7:system("cls");
		        main_menu();
		         break;
	    default:admin_menu();
	 }
	}
}
	
void buyer_menu()
{
	while(1){
		system("COLOR F0");
	system("cls");
	int choice;
	cout<<"\t----------------LILY SUPERMARKET---------------------------";
	cout<<"\n\t 1.  ADD TO CART";
    cout<<"\n\t 2.  DISPLAY ";
    cout<<"\n\t 3.  EXIT";
	cout<<"\n\t 4.  GO BACK TO MAIN MENU";
	cout<<"\n\t---------------------------------------------------";
 
	cout<<"\n\n\tChoose your option: ";
	cin>>choice;
	switch(choice)
	{
		case 1: system("cls");
			add_to_cart();
				break;
				
		case 2: system("cls");
		    display_product_menu();
				break;
				
		case 3: system("cls");
				exit(0);
				break;
				
	    case 4: system("cls");
	            main_menu();
	           break;
	    default:buyer_menu();
	           
	 }
	}
}
void main_menu()
{
	while(1){
			system("COLOR F0");
	
	system("cls");
	int choice;
	cout<<"\t-----------------MAIN MENU--------------------";
	cout<<"\n\t 1. ADMIN";
    cout<<"\n\t 2. BUYER ";
    cout<<"\n\t 3. EXIT";
	cout<<"\n\t------------------------------------------------------";
 
	cout<<"\n\n\tChoose your option: ";
	cin>>choice;
	switch(choice)
	{
		case 1: system("cls");
           authentication ();
			admin_menu();
				break;
				
		case 2: system("cls");
		   	buyer_menu();
				break;
				
		case 3: system("cls");
				exit(0);
				break;
        default: main_menu();
				
	    
	    
	           
	 }
	}
}
 
int main()
{ 
	
main_menu();
  
	
	return 0;
}

