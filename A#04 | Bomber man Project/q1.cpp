// Muhammad Azmat
// Assignment 04
// 23i-2651
// OOP-B

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Entity
{
public:
    virtual void display() const = 0;
};

class Hero : public Entity
{
private:
    char symbol;
    int row;
    int col;

public:
    Hero() : symbol('<'), row(1), col(1) {}

    char get_symbol() const { return symbol; }
    void set_symbol(char s) { symbol = s; }
    int get_row() const { return row; }
    int get_col() const { return col; }
    void set_row(int r) { row = r; }
    void set_col(int c) { col = c; }

    void display() const override
    {
        cout << symbol;
    }
};

class Bomber : public Entity
{
private:
    char symbol;
    int row;
    int col;
    bool alive;

public:
    Bomber(char s, int r, int c) : symbol(s), row(r), col(c), alive(true) {}

    int get_row() const { return row; }
    int get_col() const { return col; }
    void set_row(int r) { row = r; }
    void set_col(int c) { col = c; }
    char get_symbol() const { return symbol; }
    bool is_alive() const { return alive; }
    void set_alive(bool a) { alive = a; }

    void display() const override
    {
        cout << symbol;
    }
};

void display_grid(const char grid[23][25], const Hero &hero, const Bomber &afghani_boy, const Bomber &indian_boy, const Bomber &chinese_boy, const Bomber &russian_boy)
{
    system("cls");
    for (int i = 0; i < 23; ++i)
    {
        for (int j = 0; j < 25; ++j)
        {
            if (i == hero.get_row() && j == hero.get_col())
            {
                hero.display();
            }
            else if (i == afghani_boy.get_row() && j == afghani_boy.get_col() && afghani_boy.is_alive())
            {
                afghani_boy.display();
            }
            else if (i == indian_boy.get_row() && j == indian_boy.get_col() && indian_boy.is_alive())
            {
                indian_boy.display();
            }
            else if (i == chinese_boy.get_row() && j == chinese_boy.get_col() && chinese_boy.is_alive())
            {
                chinese_boy.display();
            }
            else if (i == russian_boy.get_row() && j == russian_boy.get_col() && russian_boy.is_alive())
            {
                russian_boy.display();
            }
            else
            {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
}

void start_game()
{
    Hero oop_boy;
    Bomber afghani_boy('E', 18, 23), indian_boy('E', 18, 2), chinese_boy('E', 6, 12), russian_boy('E', 15, 12);

    int counter = 0;
    srand(time(0));
    bool game = true;
    char input;
    char box[23][25] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', oop_boy.get_symbol(), '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', chinese_boy.get_symbol(), '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', russian_boy.get_symbol(), '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '#', '#', '#', '.', '.', '.', '#', '#', '#', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', indian_boy.get_symbol(), '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', afghani_boy.get_symbol(), '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    int new_bomber_row, new_bomber_col;
    while (game)
    {
        display_grid(box, oop_boy, afghani_boy, indian_boy, chinese_boy, russian_boy);

        cout << "Please enter your input" << endl;
        cout << "USE WASD to navigate and press x to place bomb" << endl;
        cin >> input;

        int new_hero_row = oop_boy.get_row();
        int new_hero_col = oop_boy.get_col();

        box[oop_boy.get_row()][oop_boy.get_col()] = '.'; // where the hero leaves from, that place becomes empty
        switch (input)
        {
        case 'w':
        case 'W':
            new_hero_row--;
            oop_boy.set_symbol('^');
            break;
        case 's':
        case 'S':
            new_hero_row++;
            oop_boy.set_symbol('v');
            break;
        case 'a':
        case 'A':
            new_hero_col--;
            oop_boy.set_symbol('<');
            break;
        case 'd':
        case 'D':
            new_hero_col++;
            oop_boy.set_symbol('>');
            break;
        case 'x':
        case 'X':
            if (new_hero_col + 1 < 25 && box[oop_boy.get_row()][oop_boy.get_col() + 1] != '#') // means you cannot deploy a bomb where boundaries are placed.
            {
                box[oop_boy.get_row()][oop_boy.get_col() + 1] = '%';
            }
            break;
        }

        if (box[new_hero_row][new_hero_col] == '#')
        {
            new_hero_row = oop_boy.get_row();
            new_hero_col = oop_boy.get_col();
        }

        oop_boy.set_row(new_hero_row); // responsible for movement
        oop_boy.set_col(new_hero_col);

        Bomber *bombers[] = {&afghani_boy, &indian_boy, &chinese_boy, &russian_boy};

        for (Bomber *b : bombers)
        {
            if (!b->is_alive())
            {
                continue;
            }

            new_bomber_row = b->get_row();
            new_bomber_col = b->get_col();

            int bomber_random_movement = rand() % 4;

            switch (bomber_random_movement)
            {
            case 0:
                ++new_bomber_row;
                break;

            case 1:
                --new_bomber_row;
                break;

            case 2:
                ++new_bomber_col;
                break;

            case 3:
                --new_bomber_col;
                break;
            }

            if ((new_bomber_row > 0 && new_bomber_row < 22) && (new_bomber_col > 0 && new_bomber_col < 24) && box[new_bomber_row][new_bomber_col] != '#')
            {
                if (box[new_bomber_row][new_bomber_col] == '%')
                {
                    box[b->get_row()][b->get_col()] = ' '; // when bomber dies by our trap, cout .
                    b->set_row(-1 * 1);                    // bomber B ko ghayab kar dou
                    b->set_col(-1 * 1);
                    b->set_alive(false);
                    ++counter;
                }
                else
                {
                    box[b->get_row()][b->get_col()] = '.'; // cleaning old position tah ke jab guard B move kar jae to new position, previous wali space free ho jae
                    b->set_row(new_bomber_row);
                    b->set_col(new_bomber_col);
                    box[b->get_row()][b->get_col()] = b->get_symbol();
                }
            }
        }

        box[oop_boy.get_row()][oop_boy.get_col()] = oop_boy.get_symbol();

        for (Bomber *b : bombers)
        {
            if (oop_boy.get_row() == b->get_row() && oop_boy.get_col() == b->get_col())
            {
                cout << " ** OH, THE BOMBER TOUCHED THE HERO, GAME OVER ** ";
                game = false;
            }
        }
        if (counter == 5)
        {
            cout << "YOU HAVE COMPLETED THE GAME :) " << endl;
            cout << "Run again to play again!! " << endl;
            game = false;
        }
    }
};

int main()
{
    bool running = true;
    int choice;

    system("cls");
    cout << " Welcome to the Bomber game" << endl;
    cout << "1 Start Game" << endl;
    cout << "2 Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        start_game();
        break;
    case 2:
        running = false;
        break;
    default:
        cout << "Invalid choice" << endl;
        exit(0);
    }

    return 0;
}
