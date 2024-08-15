// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
#include <string>

using namespace std;

class TextFile
{
private:
    string file_name;
    char **content;
    int lineCount;

public:
    TextFile() {}

    TextFile(string name) : file_name(name), lineCount(0)
    {
        content = new char *[100];
        for (int i = 0; i < 100; i++)
        {
            content[i] = new char[61];
        }
    }

    ~TextFile()
    {
        for (int i = 0; i < 100; i++)
        {
            delete[] content[i];
        }
        delete[] content;
    }

    void addLine(const string &line)
    {
        if (lineCount < 100)
        {
            for (int i = 0; i < 60; i++)
            {
                if (i < line.size())
                {
                    content[lineCount][i] = line[i];
                }
                else
                {
                    content[lineCount][i] = '\0';
                    break;
                }
            }
            content[lineCount][60] = '\0';
            ++lineCount;
        }
        else
        {
            cout << "** Maximum line limit reached! **" << endl;
        }
    }

    void view()
    {
        for (int i = 0; i < lineCount; i++)
        {
            cout << content[i] << endl;
        }
    }

    void editLine(int line, const string &text)
    {
        if (line >= 0 && line < lineCount)
        {
            for (int i = 0; i < 60; i++)
            {
                if (i < text.size())
                {
                    content[line][i] = text[i];
                }
                else
                {
                    content[line][i] = '\0';
                    break;
                }
            }
            content[line][60] = '\0';
        }
        else
        {
            cout << "** Invalid Line Number **" << endl;
        }
    }

    void findAndReplace(string &line, const string &oldWord, const string &newWord)
    {

        int lineSize = line.size();
        int oldWordSize = oldWord.size();
        int newWordSize = newWord.size();

        for (int i = 0; i <= lineSize - oldWordSize; i++)
        {
            bool found = true;
            // Check if oldWord matches at position i
            for (int j = 0; j < oldWordSize; j++)
            {
                if (line[i + j] != oldWord[j])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {

                string newLine;

                for (int k = 0; k < i; k++)
                {
                    newLine += line[k];
                }
                for (int k = 0; k < newWordSize; k++)
                {
                    newLine += newWord[k];
                }
                for (int k = i + oldWordSize; k < lineSize; k++)
                {
                    newLine += line[k];
                }

                line = newLine;
                i += newWordSize - 1;
                lineSize = line.size();
            }
        }
    }
    void replaceWord(const string &oldWord, const string &newWord)
    {
        for (int i = 0; i < lineCount; i++)
        {
            string line(content[i]);

            findAndReplace(line, oldWord, newWord);

            for (int j = 0; j < 60; j++)
            {
                if (j < line.size())
                {
                    content[i][j] = line[j];
                }
                else
                {
                    content[i][j] = '\0';
                    break;
                }
            }
            content[i][60] = '\0';
        }
    }

    void countWordsAndChars(int &wordCount, int &charCount)
    {
        wordCount = 0;
        charCount = 0;
        for (int i = 0; i < lineCount; i++)
        {
            string line(content[i]);
            bool inWord = false;
            for (char c : line)
            {
                if (isspace(c))
                {
                    inWord = false;
                }
                else
                {
                    charCount++;
                    if (!inWord)
                    {
                        inWord = true;
                        wordCount++;
                    }
                }
            }
        }
    }

    // void displayStatistics() const {
    //     int totalLines = lineCount;
    //     int totalWords = 0;
    //     int minWords = INT_MAX;
    //     int maxWords = 0;
    //     int charFrequency[256] = {0};

    //     for (int i = 0; i < lineCount; ++i) {
    //         int wordCount = 0;
    //         string line(content[i]);
    //         bool inWord = false;
    //         for (char c : line) {
    //             if (c==' ' || c=='\t' || c=='\n') {
    //                 inWord = false;
    //             } else {
    //                 charFrequency[(unsigned char)c]++;
    //                 if (!inWord) {
    //                     inWord = true;
    //                     wordCount++;
    //                 }
    //             }
    //         }
    //         totalWords += wordCount;
    //         minWords = min(minWords, wordCount);
    //         maxWords = max(maxWords, wordCount);
    //     }

    //     double averageWords = totalLines ? static_cast<double>(totalWords) / totalLines : 0.0;

    //     cout << "Total lines: " << totalLines << endl;
    //     cout << "Average words per line: " << averageWords << endl;
    //     cout << "Minimum words in a line: " << minWords << endl;
    //     cout << "Maximum words in a line: " << maxWords << endl;
    //     cout << "Character frequency: " << endl;
    //     for (int i = 0; i < 256; ++i) {
    //         if (charFrequency[i] > 0) {
    //             cout << (char)i << ": " << charFrequency[i] << endl;
    //         }
    //     }
    // }

    const string &getName()
    {
        return file_name;
    }
    char **getContent() const
    {
        return content;
    }
};
class TextEditor
{
private:
    TextFile files[100]; // suppose karo
    int fileCount = 0;

public:
    TextEditor()
    {
        fileCount = 0;
    }

    void run()
    {
        int choice;
        do
        {
            displayMenu();
            cin >> choice;
            handleChoice(choice);
        } while (choice != 9);
    }

    void displayMenu() const
    {
        cout << "Main Menu:" << endl;
        cout << "1. Create a new file." << endl;
        cout << "2. View an existing file." << endl;
        cout << "3. Edit an existing file." << endl;
        cout << "4. Copy an existing file to a new file." << endl;
        cout << "5. Delete an existing file." << endl;
        cout << "6. View a list of all files." << endl;
        cout << "7. Count words or characters in an existing file." << endl;
        cout << "8. Display file statistics." << endl;
        cout << "9. Exit." << endl;
        cout << "Enter your choice: ";
    }

    void handleChoice(int choice)
    {
        switch (choice)
        {
        case 1:
            createFile();
            break;
        case 2:
            viewFile();
            break;
        case 3:
            editFile();
            break;
        case 4:
            copyFile();
            break;
        case 5:
            deleteFile();
            break;
        case 6:
            listFiles();
            break;
        case 7:
            countWordsOrChars();
            break;
            // case 8: displayStatistics(); break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
    bool doesFileExist(const string &fileName)
    {
        for (int i = 0; i < 100; ++i)
        { // Assuming files is an array of size 100
            if (files[i].getName() == fileName)
            {
                return true;
            }
        }
        return false;
    }
    void createFile()
    {
        string fileName;
        cout << "Enter the new file name: ";
        cin >> fileName;

        if (doesFileExist(fileName))
        {
            cout << "File with the same name already exists!" << endl;
            return;
        }

        int numLines;
        cout << "Enter the number of lines: ";
        cin >> numLines;

        TextFile newFile(fileName);
        cin.ignore();
        for (int i = 0; i < numLines; ++i)
        {
            string line;
            cout << "Enter line " << i + 1 << ": ";
            getline(cin, line);
            newFile.addLine(line);
        }
        if (fileCount < 100)
        {
            files[fileCount++] = newFile;
            cout << "File created successfully." << endl;
        }
        else
        {
            cout << "Maximum number of files reached. Cannot add new file." << endl;
        }
    }

    void viewFile()
    {
        string fileName;
        cout << "Enter the file name to view: ";
        cin >> fileName;

        int foundIndex = -1;
        for (int i = 0; i < fileCount; ++i)
        {
            if (files[i].getName() == fileName)
            {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1)
        {
            char **content = files[foundIndex].getContent();
            for (int i = 0; i < 100; ++i)
            { // Assuming a maximum of 100 lines
                if (content[i][0] == '\0')
                    break; // if empty line tou break the loop
                cout << content[i] << endl;
            }
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }

    void editFile()
    {
        string fileName;
        cout << "Enter the file name to edit: ";
        cin >> fileName;

        int foundIndex = -1;
        for (int i = 0; i < fileCount; i++)
        {
            if (files[i].getName() == fileName)
            {
                foundIndex = i;
                break;
            }
        }

        int lineNumber;
        cout << "Enter the line number to edit:";
        cin >> lineNumber;
        cin.ignore();
        string newText;
        cout << "Enter the new text: ";
        getline(cin, newText);

        files[foundIndex].editLine(lineNumber, newText);

        char choice;
        cout << "Do you want to replace a specific word in the file? (y/n): ";
        cin >> choice;
        if (choice == 'y')
        {
            string oldWord, newWord;
            cout << "Enter the word to replace: ";
            cin >> oldWord;
            cout << "Enter the new word: ";
            cin >> newWord;
            files[foundIndex].replaceWord(oldWord, newWord);
        }
    }

    void copyFile()
    {
        string srcFileName, newFileName;
        cout << "Enter the source file name: ";
        cin >> srcFileName;
        cout << "Enter the new file name: ";
        cin >> newFileName;

        int srcIndex = -1;
        for (int i = 0; i < fileCount; ++i)
        {
            if (files[i].getName() == srcFileName)
            {
                srcIndex = i;
                break;
            }
        }

        if (srcIndex != -1)
        {
            bool fileExists = false;
            for (int i = 0; i < fileCount; ++i)
            {
                if (files[i].getName() == newFileName)
                {
                    fileExists = true;
                    break;
                }
            }

            if (!fileExists)
            {
                files[fileCount++] = files[srcIndex];
                cout << "File copied successfully." << endl;
            }
            else
            {
                cout << "File name already exists!" << endl;
            }
        }
        else
        {
            cout << "Source file not found!" << endl;
        }
    }

    void deleteFile()
    {
        string fileName;
        cout << "Enter the file name to delete: ";
        cin >> fileName;

        int foundIndex = -1;
        for (int i = 0; i < fileCount; ++i)
        {
            if (files[i].getName() == fileName)
            {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1)
        {
            for (int j = foundIndex; j < fileCount - 1; ++j)
            {
                files[j] = files[j + 1];
            }
            --fileCount;
            std::cout << "File deleted successfully." << std::endl;
        }
        else
        {
            std::cout << "File not found!" << std::endl;
        }
    }

    void listFiles()
    {
        if (fileCount == 0)
        {
            cout << "No files available." << endl;
        }
        else
        {
            cout << "List of files:" << endl;
            for (int i = 0; i < fileCount; ++i)
            {
                cout << files[i].getName() << endl;
            }
        }
    }

    void countWordsOrChars()
    {
        string fileName;
        cout << "Enter the file name to count words/characters: ";
        cin >> fileName;
        bool found = false;
        int foundIndex = -1;
        for (int i = 0; i < fileCount; ++i)
        {
            if (files[i].getName() == fileName)
            {
                foundIndex = i;
                found = true;
                break;
            }
        }
        if (found == true)
        {
            int wordCount = 0;
            int charCount = 0;
            files[foundIndex].countWordsAndChars(wordCount, charCount);
            cout << "Word count: " << wordCount << endl;
            cout << "Character count: " << charCount << endl;
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }

    // void displayStatistics() {
    //     string fileName;
    //     cout << "Enter the file name to display statistics: ";
    //     cin >> fileName;
    //     auto it = files.find(fileName);
    //     if (it != files.end()) {
    //         it->second.displayStatistics();
    //     } else {
    //         cout << "File not found!" << endl;
    //     }
    // }
};

int main()
{
    TextEditor editor;
    editor.run();
    return 0;
}