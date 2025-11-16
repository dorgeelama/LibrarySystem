#include<iostream>

struct Book{
  int id{};
  std::string name{};
  int quantity{};
  int borrowed{};
};

struct User {
  std::string name{};
  int id{};
  int currentAmountOfBooksBorrowed{0};
  int borrowed_books[100]{};
};

const int listOfBookSize = 100;
const int userBaseSize = 100;
int bookPosition = 0;
int userPosition = 0;
Book listOfBooks[listOfBookSize]{};
User listOfUsers[userBaseSize]{};
int menu(){
  int choice = -1;
  while (choice == -1){
    std::cout << "Library Menu:\n";
    std::cout << "1) add_book\n";
    std::cout << "2) search_books_by_prefix\n";
    std::cout << "3) print_who_borrowed_book_by_name\n";
    std::cout << "4) print_library_by_id\n";
    std::cout << "5) print_library_by_name\n";
    std::cout << "6) add_user\n";
    std::cout << "7) user_borrow_book\n";
    std::cout << "8) user_return_book\n";
    std::cout << "9) print_users\n";
    std::cout << "10) Exit\n";


    std::cin >> choice;


    if(!(1<= choice <= 10)){
      std::cout << "Invalid choice. Try again\n";
      choice = -1;
    }
  }
  return choice;
}

void print_books() {
  for(int i = 0; i < bookPosition; i++){
    std::cout << "id = " << listOfBooks[i].id << " "
              << "name = " << listOfBooks[i].name << " "
              << "total_quanity " << listOfBooks[i].quantity << " "
              << "total_borrowed " << listOfBooks[i].borrowed << "\n";
  }
}

void add_book(){
  int id, quantity;
  std::string name;
  std::cout << "Enter book info: id & name & total quantity: ";
  std::cin >> id >> name >> quantity;
  listOfBooks[bookPosition] = Book{id, name, quantity};
  bookPosition++;
}

void print_library_by_id(){
  for(int i = 0; i < bookPosition; i++){
    for(int j = i + 1; j < bookPosition; j++){
      if(listOfBooks[j].id < listOfBooks[i].id){
        Book hold = listOfBooks[j];
        listOfBooks[j] = listOfBooks[i];
        listOfBooks[i] = hold;
      }
    }
  }
  print_books();
}


void print_library_by_name(){
  for(int i = 0; i < bookPosition; i++){
    for(int j = i + 1; j < bookPosition; j++){
      if(listOfBooks[j].name < listOfBooks[i].name){
        Book hold = listOfBooks[j];
        listOfBooks[j] = listOfBooks[i];
        listOfBooks[i] = hold;
      }
    }
  }
  print_books();
}

void add_user() {
  std::string name;
  int id;
  std::cout << "Enter user name & national id: \n";
  std::cin >> name >> id; 
  listOfUsers[userPosition] = User{name, id};
  userPosition++;
}

void print_users(){
  for(int i = 0; i < userPosition; i++){
    std::cout << "user " << listOfUsers[i].name << " " 
              << "id " << listOfUsers[i].id << " "
              << "borrowed books ids: ";
    for(int j = 0; j < listOfUsers[i].currentAmountOfBooksBorrowed; j++){
      std::cout << listOfUsers[i].borrowed_books[j] << " ";
    }
    std::cout << "\n";
  }
  
}

int findBookByName(std::string bookName){
  for(int i = 0; i < bookPosition; i++){
    if(listOfBooks[i].name == bookName){
      listOfBooks[i].borrowed++;
      return listOfBooks[i].id;
    }
  }
  return 0;
}

void user_borrow_book(){
  std::string name, bookName;
  std::cout << "Enter user name and book name: \n";
  std::cin >> name >> bookName;

  for(int i = 0; i < userBaseSize; i++){
    if(listOfUsers[i].name == name){
      listOfUsers[i].borrowed_books[listOfUsers[i].currentAmountOfBooksBorrowed] = findBookByName(bookName);
      listOfUsers[i].currentAmountOfBooksBorrowed++;
    }
  }



}


void hospital_system(){
  while (true){
    int choice = menu();
    if(choice == 1){
      add_book();
    }
    else if (choice == 2){
      std::cout << "search_books_by_prefix\n";
    }
    else if (choice == 3){

    }
    else if (choice == 4){
      print_library_by_id();
    }
    else if (choice == 5){
      print_library_by_name();
      
    }
    else if (choice == 6){
      add_user();

    }
    else if (choice == 7){
      user_borrow_book();

    }
    else if (choice == 8){

    }
    else if (choice == 9){
      print_users();
    }
    else if (choice == 10){
      break;
    }
  }
}




int main() {
  hospital_system();
  return 0;
}
