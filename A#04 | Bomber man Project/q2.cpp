// Muhammad Azmat
// Assignment 04
// 23i-2651
// OOP-B

#include <iostream>
#include <string>

using namespace std;

class library_item
{
protected:
    string item_id;
    string title;
    string author;
    bool available;

public:
    library_item()
    {
        item_id = "";
        title = "";
        author = "";
        available = false;
    }
    library_item(string id, string titlee, string writer)
    {
        item_id = id;
        title = titlee;
        author = writer;
        available = true;
    }

    string get_item_id() { return item_id; }
    string get_title() { return title; }
    string get_author() { return author; }
    bool get_availibility() { return available; }
    bool set_availibility(bool a) { available = a; }

    virtual void display_deets()
    {
        cout << "The Author's name: " << author << endl;
        cout << "The Book's name: " << title << endl;
        cout << "The Book's ID: " << item_id << endl;
        cout << "Availibility: " << available << endl;
    }

    void check_out()
    {
        available = false;
    }

    void return_item()
    {
        available = true;
    }

    virtual ~library_item()
    {
    }
};

class book : public library_item
{
private:
    string genre;
    int page_count;

public:
    book(string id, string titlee, string writer, string genree, int pg_count)
        : library_item(id, titlee, writer), genre(genree), page_count(pg_count) {}

    string get_genre() { return genre; }
    int get_pg_count() { return page_count; }

    void display_deets() override
    {
        library_item ::display_deets();
        cout << "The Books's Genre is: " << genre << endl;
        cout << "The Book's total pages are: " << page_count << endl;
    }
};

class dvd : public library_item
{
private:
    int duration;
    string rating;

public:
    dvd(string id, string titlee, string writer, int durationn, string ratingg)
        : library_item(id, titlee, writer), duration(durationn), rating(ratingg) {}

    int get_duration_time() { return duration; }
    string get_rating() { return rating; }

    void display_deets() override
    {
        library_item::display_deets();
        cout << "The duration of DVD in minutes is: " << duration << endl;
        cout << "The rating of this DVD is: " << rating << endl;
    }
};

class magazine : public library_item
{
private:
    int issue_no;
    string publish_month;

public:
    magazine(string id, string titlee, string writer, int issue_num, string pub_month)
        : library_item(id, titlee, writer), issue_no(issue_num), publish_month(pub_month) {}

    int get_issue_no() { return issue_no; }
    string get_publish_month() { return publish_month; }

    void display_deets() override
    {
        library_item::display_deets();
        cout << "The issue number of this magazine is: " << issue_no << endl;
        cout << "The publish month of this magazine is: " << publish_month << endl;
    }
};

class library
{
private:
    library_item **items;
    int count;
    int total_capacity;

    void resize()
    {
        total_capacity = total_capacity * 2;
        library_item **new_items = new library_item *[total_capacity];
        for (int i = 0; i < count; ++i)
        {
            new_items[i] = items[i];
        }
        delete[] items;
        items = new_items;
    }

public:
    library()
    {
        count = 0;
        total_capacity = 5;
        items = new library_item *[total_capacity];
    }

    ~library()
    {
        for (int i = 0; i < total_capacity; i++)
        {
            delete[] items[i];
        }
        delete[] items;
    }

    void add_item(library_item *item)
    {
        if (count == total_capacity)
        {
            resize();
        }
        items[count++] = item;
    }

    void removeItem(const string &item_idd)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->get_item_id() == item_idd) // check this later.
            {
                delete items[i];
                for (int j = i; j < count - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                --count;
                return;
            }
        }
    }

    void display_all_items() const
    {
        for (int i = 0; i < count; i++)
        {
            items[i]->display_deets();
            cout << endl;
        }
    }

    void check_out_item(const string &item_id)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->get_item_id() == item_id)
            {
                items[i]->set_availibility(false);
            }
        }
    }

    void return_item(const string &item_id)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->get_item_id() == item_id)
            {
                items[i]->set_availibility(true);
            }
        }
    }

    library_item *find_item_by_id(const string &item_id) // using a ptr to library_item because of DMA, also using this base class ptr to access derived classes attributes which they inherited from base class
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->get_item_id() == item_id)
            {
                return items[i];
            }
        }
    }

    void recommendation(const string &genre)
    {
        for (int i = 0; i < count; i++)
        {
            book *books = dynamic_cast<book *>(items[i]);
            if (books && books->get_genre() == genre)
            {
                books->display_deets();
                cout << endl;
                cout << endl;
            }
        }
    }

    library_item *search_item_by_title(const string &titlee) const
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->get_title() == titlee)
            {
                return items[i];
            }
        }
    }

    library_item *search_item_by_author(const string &authorr) const
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i]->get_author() == authorr)
            {
                return items[i];
            }
        }
    }

    void sort_by_title()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (items[i]->get_title() > items[j]->get_title())
                {
                    library_item *temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
                }
            }
        }
        return;
    }

    void sort_by_author()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (items[i]->get_author() > items[j]->get_author())
                {
                    library_item *temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
                }
            }
        }
        return;
    }
};

void menu()
{
    cout << "** WELCOME TO LIBRARY MANAGEMENT SYSTEM ** " << endl;
    cout << endl;
    cout << "You can use the following features in our Library!! " << endl;
    cout << "ADD ITEM" << endl;
    cout << "REMOVE ITEM" << endl;
    cout << "DISPLAY ALL ITEMS" << endl;
    cout << "CHECK OUT ITEM" << endl;
    cout << "RETURN ITEM" << endl;
    cout << "FIND ITEM BY ID" << endl;
    cout << "SORT ITEMS BY TITLE " << endl;
    cout << "SORT ITEMS BY AUTHOR " << endl;
    cout << "SEARCH ITEMS BY TITLE" << endl;
    cout << "SEARCH ITEMS BY AUTHOR" << endl;
    cout << "QUIT THE SYSTEM" << endl;
}

int main()
{
    library example;

    example.add_item(new book("00B1", "Your Head is a Houseboat", "Campbell Walker", "Self-help", 247));
    example.add_item(new book("00B2", "How to Win Friends", "Dale Carnegie", "Self-help", 174));
    example.add_item(new dvd("00D1", "GTA V", "Rockstar Games", 200, "R-18"));
    example.add_item(new dvd("00D2", "FIFA 24", "EA Sports", 500, "Pegi-3"));
    example.add_item(new magazine("00M1", "Discover Pakistan", "Multiple Artists", 11, "April 2022"));
    example.add_item(new magazine("00M2", "Formula 1", "Andrew Applepie", 12, "November 2022"));

    cout << "Displaying all items in the library:" << endl;
    example.display_all_items();
    cout << endl;

    // Sorting by title
    cout << "Sorting items by title:" << endl;
    example.sort_by_title();
    example.display_all_items();
    cout << endl;
    cout << endl;

    // Sorting by author
    cout << "Sorting items by author:" << endl;
    example.sort_by_author();
    example.display_all_items();
    cout << endl;
    cout << endl;

    // Checking out item
    cout << "Checking out the book: Your Head is a Houseboat" << endl;
    example.check_out_item("00B1");
    example.display_all_items();
    cout << endl;

    // Returning item
    cout << "Returning the book: Your Head is a Houseboat" << endl;
    example.return_item("00B1");
    example.display_all_items();
    cout << endl;

    // Finding item by ID
    cout << "Finding item by ID \"00D1\":" << endl;
    library_item *item = example.find_item_by_id("00D1");
    if (item)
    {
        item->display_deets();
    }
    else
    {
        cout << "Item couldn't be found, Try again!" << endl;
    }
    cout << endl;

    // Recommendation according to genre
    cout << "Recommending items by genre 'Classic':" << endl;
    example.recommendation("Selp-help");
    cout << endl;

    // Searching item by title
    cout << "Searching for item by title \"FIFA 24\":" << endl;
    item = example.search_item_by_title("FIFA 24");
    if (item)
    {
        item->display_deets();
    }
    else
    {
        cout << "Item not found." << endl;
    }
    cout << endl;

    // Searching item by author
    cout << "Searching for item by author \"Campbell Walker\":" << endl;
    item = example.search_item_by_author("Campbell Walker");
    if (item)
    {
        item->display_deets();
    }
    else
    {
        cout << "Item not found." << endl;
    }
    cout << endl;

    // Removing item
    cout << "Removing item '00M2':" << endl;
    example.removeItem("00M2");
    example.display_all_items();
    cout << endl;

    return 0;
}