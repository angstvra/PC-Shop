#include<iostream>
#include<string.h>  
#include <stdio.h>     
#include<process.h>       
#include<dos.h>  
#include<windows.h>
#include<stdlib.h>
using namespace std;

void insITEM1(int itemNum, char itemNAME[30], int itemQTY, float itemPrice);
void insITEM2(int pos, int itemNum, char itemNAME[30], int cpuQTY, float itemPrice);
void insITEM3(int itemNum, char itemNAME[30], int itemQTY, float itemPrice);
void updateITEMList(int updItemNum, int updItemQTY);
void removeITEM(int itemSerial);


void main_menu();
void loadingbar();
void updatebar();
void itemlist();

struct Node{

	char itemNAME[50];
	int itemQTY;
	float itemPrice;
	int itemNum;
	struct Node *next;

};

typedef struct Node node ;

node *head, *list;


main(){
	
	int bal, pay, change, cont;
	float totalmoney = 0;
	int c = 0;
	int cardno[100];
	float creditMoney[100];
	
	int total_order[100];
	int order_itemQTY[100];
	int order=0;
	int updItemQTY;	
	
	head = NULL;
	
	insITEM1(1,"Intel i9 9900", 7, 18800);
	insITEM3(2,"Intel i9 9900K", 10, 17300);
	insITEM3(3,"Ryzen 9 5950X", 3, 38500);
	insITEM3(4,"Ryzen 7 5800X", 8, 29400);
	insITEM3(5,"Nvidia GeForce RTX 2080 Ti", 5, 48000);
	insITEM3(6,"Nvidia GeForce GTX 1660 Ti", 6, 13500);
	insITEM3(7,"Nvidia GeForce RTX 3090", 1, 72000);
	insITEM3(8,"DDR4 2x8GB 3200MHz", 10, 3500);
	insITEM3(9,"DDR4 1x16GB 3200MHz", 10, 3000);
	insITEM3(10,"Samsung 970 SSD 250GB", 8, 2900);
	insITEM3(11,"Samsung 980 Pro SSD 500GB", 7, 6700);
	insITEM3(12,"Gigabyte Z390 Aorus Pro", 5, 9500);
	insITEM3(13,"ASUS ROG Maximus XI Gene", 2, 17000);
	insITEM3(14,"Gigabyte X570 AORUS Elite", 2, 11000);
	
	loadingbar();
	mainmenu:
	main_menu();

	int mainUserInput;
	
	cout << "\n\n\t\t\t\t\tEnter here: ";
	cin >> mainUserInput;
	system("cls");
	if((mainUserInput >=1 && mainUserInput <=3)){

		if(mainUserInput == 1){

				system("cls");
				itemlist:
				itemlist();
		int itemChoice;

	cout << "\n\n\t\t\tSelect the item of your choice [0 to exit]: " ;
	cin >> itemChoice;

	if(itemChoice==0){
		system("cls");
		goto mainmenu;
}

	node *temp;

	temp = list ;

	while(temp->itemNum != itemChoice){

		temp = temp->next;
		if(temp==NULL){
			cout << "\n\nPlease choose: ";Sleep(1000);
			system("cls");
			goto itemlist;
}

}
	if(itemChoice == temp->itemNum){
		userItemQTY:
		
		cout << "\n\n\t\t\tEnter number of item(s): ";

		int userItemQTY;
		cin >> userItemQTY; 
		system("cls");

		if(userItemQTY==0){
			system("cls"); 
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tAmount of item(s) cannot be 0"; 
			Sleep(2000);
			system("cls");
			goto itemlist;
}
		else if(userItemQTY>temp->itemQTY){
			system("cls"); 
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tItem currently out of stock. Please come again later. Thank you!"; Sleep(2000);
			system("cls");
			goto itemlist;
}
		
				float qtyPrice = temp->itemPrice*userItemQTY;
				float dis;
				float temp1;
		if(userItemQTY > 2){
	dis = (temp->itemPrice*userItemQTY) * 10 / 100;
		
		temp1 = qtyPrice - dis;
		qtyPrice = temp1;
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t" << temp->itemNAME << " is priced " << qtyPrice << " with a 10% discount."; 
}
	else{
		dis = 0;
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t" << temp->itemNAME << " is priced " << qtyPrice; 
}		
		
		cout << "\n\n\t\t\t\t\t[1] Confirm purchase. \n\n";
		cout << "\n\n\t\t\t\t\t[2] Go to item list. \n\n";	
		isConfirm:
		int confirm;

		fflush(stdin); 
		cin >> confirm;

		system("cls");

		if(confirm == 1 ){

			
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t[1] Cash\n\n";
			
            cout << "\n\n\t\t\t\t\t[2] Credit\n\n";
            
			payment:
			int payment;

			 cin >> payment;

			// PAY THROGUH CASH

			if(payment==1){

				
				totalmoney += qtyPrice;
				order++;
				total_order[order]=itemChoice;
				order_itemQTY[order]=userItemQTY;
				updItemQTY = temp->itemQTY - userItemQTY;
				updateITEMList(itemChoice,updItemQTY);


				system("cls");  
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tProcessing your purchase...";
				Sleep(500);
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTransaction successful!";
				Sleep(500);
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t[1] Would you like to purchase another? \n\n";
				cout << "\n\n\t\t\t\t\t[2] Main Menu \n\n";
				cout << "\n\n\t\t\t\t\tEnter here: ";
				
				menuPrompt:
				int promptChoice;

				fflush(stdin);  
				cin >> promptChoice;
				
				
				if(promptChoice==1){
					system("cls");
				goto itemlist;
}
				else if(promptChoice==2){
					system("cls");
				goto mainmenu;
}
				else{
				cout << "Choose again: "; 
					system("cls");
				goto menuPrompt;}

}

			// PAY THROUGH CREDIT

			else if(payment==2){

				int card_number[100];

				c++;

				system("cls"); 
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter card number here: ";

				fflush(stdin);   
				cin >> card_number[c];



				cardno[c] = card_number[c];

				int pin;

				cout << "\n\n\t\t\t\t\tEnter card pin here: ";

				fflush(stdin);     
				cin >> pin;

				creditMoney[c] = qtyPrice;

				totalmoney += qtyPrice;
				order++;
				total_order[order]=itemChoice;
				order_itemQTY[order]=userItemQTY;

				updItemQTY = temp->itemQTY - userItemQTY;

				updateITEMList(itemChoice,updItemQTY);

				system("cls");  
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSwiping card...";
				Sleep(1000);
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tTransaction successful!";
				Sleep(500);
				system("cls");
				
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t[1] Would you like to purchase another? \n\n";
				cout << "\n\n\t\t\t\t\t[2] Main Menu \n\n";
				cout << "\n\n\t\t\t\t\tEnter here: ";
				
				menuPrompt2:
				int promptChoice2;
				cin >> promptChoice2;

				if(promptChoice2==1){
					system("cls");
				goto itemlist;}
				
				else if(promptChoice2==2){
					system("cls");
				goto mainmenu;}
			
				else{
				cout << "Choose again: "; 
					system("cls");
				goto menuPrompt2;}

}

			else{

			   cout << "Please choose from the list: ";

				goto payment;


}


}   



		else if(confirm == 2){
			system("cls");
			goto itemlist;

}

		else{
		   cout << "Please select from the list: ";
			system("cls");
			goto isConfirm;
} 
}  

	else{

	cout << "Please select from the list: "; Sleep(300);
		system("cls");
		goto itemlist;
}  
}

 //
 //

// ADMIN PANEL 



		else if( mainUserInput == 2){			
			string adminInput;
			int adminChoice;
			int attemptCount=0;
			const string PASSWORD = "12345";
						
			
			
			
			
				while(attemptCount<3)
	{
		cout << "\n\n\t\t\tPlease enter admin password: ";
			cin >> adminInput;
		if(adminInput!=PASSWORD){
			cout<<"\n\n\t\t\tIncorrect Pin. Please Try Again"<<endl;
			attemptCount++;
			if(attemptCount==3){
				system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tLogging out...";
				Sleep(1000);
				system("cls");
			return 0;
		}
		}
		else{
			break;
		}
	}
			system("cls");	
				
				
		if(adminInput.compare(PASSWORD) == 0){
			adminpanelchoice:	
				
			cout << "\n\n\n\t\t\t\t\t\[0] Main menu";
			cout << "\n\n\t\t\t\t\t\[1] View total cash generated today";
			cout << "\n\n\t\t\t\t\t\[2] View total payment through card";
			cout << "\n\n\t\t\t\t\t\[3] Restock items";
			cout << "\n\n\t\t\t\t\t\[4] Add new product"	;
			cout << "\n\n\t\t\t\t\t\[5] Remove a product";	
			cout << "\n\n\t\t\t\t\t\[6] Display all the items\n\n";	
			cin >> adminChoice;
			
			system("cls");	
							
			if(adminChoice == 0){
				system("cls");
				goto mainmenu;
}			
			else if(adminChoice==1){
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tToday's money: " << totalmoney;
			Sleep(2000);
			system("cls");
				goto adminpanelchoice;
}			
				// CREDIT				
			else if(adminChoice == 2){
					if(c!=0){
						system("cls");
						cout << "\n\n\n\n\n\n\t\t\t\t\t\ ____________________________\n";
						cout << "\n\n\n\n\n\n\t\t\t\t\t\|   Card NO.   |   Money $   |\n";
						cout << "\n\n\n\n\n\n\t\t\t\t\t\------------------------------\n";
						for(int l=1; l<=c;l++){
							printf("\n\n\t\t\t\t\t\|  %d      |   %0.2f    |\n",cardno[l],creditMoney[l]);

							
}
						system("pause");
}
					if(c==0){
						system("cls");  
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThere is no history of payment through credit.\n";}
					
				
					system("cls"); 
					goto adminpanelchoice;
}		
				// REPLENISH ITEMS
				
			else if(adminChoice == 3){
				
				replenish:
				itemlist();
				int itemChoice;
				cout << "\n\n\t\t\tSelect item to replenish [Press [0] to go back]: ";
				cin >> itemChoice;
			
				if(itemChoice != 0){
				
node *temp;

temp = list ;

					while(temp->itemNum != itemChoice){

		temp = temp->next;
		if(temp==NULL){
			cout << "\n\n\t\t\t\tItem not found! Select again. ";Sleep(1000);
			system("cls");
			goto replenish;
}

}
	if(itemChoice == temp->itemNum){

		
		enterNumItem:
		cout << "\n\n\t\t\t\tEnter number of item(s) [Press [0] to go back]: ";
		int  repQTY1;
				cin >> repQTY1;
				if(repQTY1 > 0 ){
					
					updItemQTY = updItemQTY + repQTY1;
					updateITEMList(itemChoice,updItemQTY);
						system("cls");
						cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tUpdating item...";
						Sleep(1000);
						system("cls");
						cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tItem successfully updated.";
						Sleep(750);
						system("cls");
						goto adminpanelchoice;
				
				}
					
				
				else if(repQTY1 < 0){
					cout << "\n\n\t\t\t\tWe only accept amounts greater than zero (0). Please try again.\n\n";
			goto enterNumItem;
			
				}
				else
				system("cls");
				goto replenish;}
}

				else 
				system("cls");
				goto adminpanelchoice;
}

//
//

/// ADDDDDDDDDD
			else if(adminChoice == 4){
				
				addITEM:
				system("cls");

					char updateITEMList[30];
					int admItemQTY;
					int admItemNum;
					float admItemPrice;
					


    
					 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\nt\t\t\tEnter the name of the new product: ";
					fflush(stdin);    
					 
					scanf("%[^\n]s",updateITEMList);
					
					admItemQTY:
					fflush(stdin);


					cout << "\n\n\t\t\t\tEnter stocks [Press [0] to go back]:  ";
					
					cin >> admItemQTY; 
					fflush(stdin);
					if(admItemQTY < 0){
						cout << "\n\n\t\t\t\tWe only accept amounts greater than zero (0). Please try again.\n\n";
			goto admItemQTY;
					}
					else if(admItemQTY == 0){
						system("cls");
						goto adminpanelchoice;
					}
					

                        itemOrderNumber:
					  
					cout << "\n\n\t\t\t\tEnter order number for the new product [Press [0] to go back]:  ";
                      cin >> admItemNum;
                      if(admItemNum > 0){
					  
                      
                            node *current;
                            current = list;
                      while(current->itemNum!=admItemNum){
                            if(current->next==NULL){
                                break;
                            }
                        current=current->next;
                      }
                      if(current->itemNum==admItemNum){
                       
					   cout << "\n\n\t\tThe item number for the product you are currently adding already exists.\n\n\t\tPlease add another.";
                       goto itemOrderNumber;
                      }

                    admItemPrice:
                      fflush(stdin);

					cout << "\n\n\t\t\t\tEnter price for the new product [Press [0] to go back]:  ";
					fflush(stdin);

					cin >> admItemPrice;
						if(admItemPrice > 0){
						
					
					system("cls");
					 updatebar();

					insITEM3(admItemNum,updateITEMList,admItemQTY,admItemPrice);
					system("cls");
					goto adminpanelchoice;}
						else if(admItemPrice < 0){
							cout << "\n\n\t\t\t\tWe only accept amounts greater than zero (0). Please try again.\n\n";
			goto admItemPrice;
						}
						
						else system("cls");
						goto adminpanelchoice;
}
					
					else if(admItemNum < 0){
						cout << "\n\n\t\t\t\tWe only accept amounts greater than zero (0). Please try again.\n\n";
			goto itemOrderNumber;
					}
					
					else system("cls");
					goto adminpanelchoice;
				
}
//			
//			
/////////// REMOVEEEE
			else if(adminChoice == 5){
					system("cls");
					itemlist();
					cout << "\n\n\n\t\t\tEnter the order number of the item to remove [Press [0] to go back]: ";
					removeItem:
					int removeItem;
					cin >> removeItem;
					if(removeItem!=0){
					
					node *temp;
					temp = list;
					while(temp->itemNum != removeItem){
						if(temp->next==NULL){
                                break;
                            }
						temp = temp->next;
}
					if(temp->itemNum==removeItem){
						removeITEM(removeItem);
}
					else{
						
					cout << "\n\n\t\t\tOrder number does not matched to any of the existing item: ";
			 		goto removeItem;			
}
					system("cls");
					goto adminpanelchoice;
				}
				else system("cls");
				goto adminpanelchoice;
					
}

		else if(adminChoice == 6){
			system("cls");
			itemlist();
			cout << "\n\n";
			system("pause");
			system("cls");
			goto adminpanelchoice;
		}

}
	
	else{		
		cout << "Access not granted." << endl;
		Sleep(1000);
		system("cls"); 
		goto mainmenu;	
}
}


	
}
}


		// INTRO LOAD

void loadingbar(void){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\tLOADING: ";
	char a = 219;
	cout << a;
	for(int i=0;i<40;i++){
		 	cout << a;				
		Sleep(20);
}
	cout << "\n\n\t\t\t\t\t\t\tCOMPLETED!" << endl;
	cout << "\n\n\n\t\t\t\t\t\t";
	system("pause");
	system("cls");
}	
		
		// UPDATE LOAD
		
void updatebar(void){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\tUPDATING: ";
	char a = 219;
	cout << a;
	for(int i=0;i<40;i++){
		 	cout << a;				
		Sleep(20);
}
	cout << "\n\n\t\t\t\t\t\tUPDATE COMPLETE!" << endl;
	cout << "\n\n\n\t\t\t\t\t\t";
	system("pause");
	system("cls");
}	
		
		// MENU

void main_menu(){
	
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t[1] >> Item List" << endl;
	cout << "\n\n\t\t\t\t\t\t[2] >> Admin authorization" << endl;
	cout << "\n\n\t\t\t\t\t\t[3] >> Exit" << endl;
	
}



		// ITEM LIST

void itemlist(){



	cout << "\n\t\t"; 
	cout << "\n\t\t"; 
	cout << "|  Item No.  |   Item Name       |  Price  	|   In Stock   |";
	cout << "\n\t\t"; 
	

	node *temp;

	temp = list;

	while(temp != NULL){

		


		cout << "\n\t\t";  
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->itemNum,temp->itemNAME, temp->itemPrice, temp->itemQTY);
		
		cout << "\n\t\t";


		temp = temp->next ; 
		Sleep(25);

}





}




void insITEM1(int itemNum, char itemNAME[30], int itemQTY, float itemPrice){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->itemNum = itemNum ;

	temp->itemPrice = itemPrice;

	strcpy(temp->itemNAME,itemNAME);

	temp-> itemQTY = itemQTY;


	temp->next = head;

	head = temp;

	list = head ;

}

void insITEM2(int pos, int itemNum, char itemNAME[30], int itemQTY, float itemPrice){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->itemNum = itemNum;

	temp->itemPrice = itemPrice;

	temp-> itemQTY = itemQTY;

	strcpy(temp->itemNAME,itemNAME);

	while(head->next->itemNum != pos ){


		head = head->next ;

}

	temp->next = head->next;
	head->next = temp ;


}

void insITEM3(int itemNum, char itemNAME[30], int itemQTY, float itemPrice){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->itemNum = itemNum;

	temp->itemPrice = itemPrice;

	temp-> itemQTY = itemQTY;

	strcpy(temp->itemNAME,itemNAME);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
}
	else{

		while(head->next != NULL){
			head = head->next;
}

		head->next = temp;
}

}






void removeITEM(int itemSerial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->itemNum != itemSerial){

		while(temp->next->itemNum != itemSerial){
			temp = temp->next;
}

		if(temp->next->itemNum == itemSerial){

			temp->next = temp->next->next;
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\Deleting item " << itemSerial;
			
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\t\t\t\tUPDATING: ";
			char a = 219;
			cout << a;
			for(int i=0;i<40;i++){
		 	cout << a;				
			Sleep(20);
}
	cout << "\n\n\t\t\t\t\t\tUPDATE COMPLETE!" << endl;
	cout << "\n\n\n\t\t\t\t\t\t";
	system("pause");
	system("cls");
			
		

			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\Item deleted successfully!\n"; Sleep(500);

}
		else{
			cout << "\n\n\n\n\t\t\tItem does not exist!\n"; 
			Sleep(500);
}

		head = temp ;

}
	else{

		temp = temp->next;
		system("cls");
		cout << "\n\n\n\n\t\t\tDeleting item " << itemSerial;
		
		cout << "\n\n\n";
	cout << "\t\t\t\tUPDATING: ";
	char a = 219;
	cout << a;
	for(int i=0;i<40;i++){
		 	cout << a;				
		Sleep(20);
}
	cout << "\n\n\t\t\t\t\t\tUPDATE COMPLETE!" << endl;
	cout << "\n\n\n\t\t\t\t\t\t";
	system("pause");
	system("cls");

		cout << "\n\n\n\n\t\t\tItem deleted successfully!\n"; 
		Sleep(500);

		head = temp ;

		list=head;
}
}

void updateITEMList(int updItemNum, int updItemQTY){

	node *temp;
	temp = list;

	while(temp->itemNum!=updItemNum){
		temp = temp->next;

}
	if(temp->itemNum == updItemNum){
		temp->itemQTY = updItemQTY;
}

}
