#include <bits/stdc++.h>

using namespace std;

class book
{
private:
	char *author, *title, *publisher;
	float *price_of_book;
	int *books_in_stock;

public:
	book()
	{
		author = new char[50];
		title = new char[50];
		publisher = new char[50];
		price_of_book = new float;
		books_in_stock = new int;
	}
	void Enter_book_data()
	{
		cin.ignore();
		cout << "\nEnter Author Name: ";
		cin.getline(author, 50);
		cout << "Enter Title Name: ";
		cin.getline(title, 50);
		cout << "Enter Publisher Name: ";
		cin.getline(publisher, 50);
		cout << "Enter price_of_book: ";
		cin >> *price_of_book;
		cout << "Enter books_in_stock Position: ";
		cin >> *books_in_stock;
	}

	void edit_book_data()
	{

		cout << "\nEnter Author Name: ";
		cin.getline(author, 50);
		cout << "Enter Title Name: ";
		cin.getline(title, 50);
		cout << "Enter Publisher Name: ";
		cin.getline(publisher, 50);
		cout << "Enter price_of_book: ";
		cin >> *price_of_book;
		cout << "Enter books_in_stock Position: ";
		cin >> *books_in_stock;
	}
	void show_book_data()
	{
		cout << "\nAuthor Name: " << author;
		cout << "\nTitle Name: " << title;
		cout << "\nPublisher Name: " << publisher;
		cout << "\nprice_of_book: " << *price_of_book;
		cout << "\nbooks_in_stock Position: " << *books_in_stock;
	}
	int search(char tbuy[50], char abuy[50])
	{
		if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
			return 1;
		else
			return 0;
	}

	void buy_book()
	{
		int count;
		cout << "\nEnter Number Of Books to buy: ";
		cin >> count;
		if (count <= *books_in_stock)
		{
			*books_in_stock = *books_in_stock - count;
			cout << "\nBooks Bought Successfully";
			cout << "\nAmount: Rs. " << (*price_of_book) * count;
		}
		else
			cout << "\nRequired Copies not in books_in_stock";
	}
};

int main()
{
	book *B[50];
	int i = 0, r, t, choice;
	char title_buy[50], author_buy[50];
	while (1)
	{
		cout << "\n\n\t\tMENU"
			 << "\n1. Entry of New Book"
			 << "\n2. Buy Book"
			 << "\n3. Search For Book"
			 << "\n4. Edit Details Of Book"
			 << "\n5. Exit"
			 << "\n\nEnter your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			B[i] = new book;
			B[i]->Enter_book_data();
			i++;
			break;

		case 2:
			cin.ignore();
			cout << "\nEnter Title Of Book: ";
			cin.getline(title_buy, 50);
			cout << "Enter Author Of Book: ";
			cin.getline(author_buy, 50);
			for (t = 0; t < i; t++)
			{
				if (B[t]->search(title_buy, author_buy))
				{
					B[t]->buy_book();
					break;
				}
			}
			if (t == 1)
				cout << "\nThis Book is Not in books_in_stock";

			break;
		case 3:
			cin.ignore();
			cout << "\nEnter Title Of Book: ";
			cin.getline(title_buy, 50);
			cout << "Enter Author Of Book: ";
			cin.getline(author_buy, 50);

			for (t = 0; t < i; t++)
			{
				if (B[t]->search(title_buy, author_buy))
				{
					cout << "\nBook Found Successfully";
					B[t]->show_book_data();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in books_in_stock";
			break;

		case 4:
			cin.ignore();
			cout << "\nEnter Title Of Book: ";
			cin.getline(title_buy, 50);
			cout << "Enter Author Of Book: ";
			cin.getline(author_buy, 50);

			for (t = 0; t < i; t++)
			{
				if (B[t]->search(title_buy, author_buy))
				{
					cout << "\nBook Found Successfully";
					B[t]->edit_book_data();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in books_in_stock";
			break;

		case 5:
			exit(0);
		default:
			cout << "\nInvalid Choice Entered";
		}
	}

	return 0;
}