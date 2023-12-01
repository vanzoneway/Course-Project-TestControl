//readqfile.h
#include "readqfile.h"


//parses all "Test %1.txt".arg in QMap<int, QMap<QString, QString> and
// QMap<String, String> has folowing keys ( in switch construction u can check
// In wrapper map int - is number of slide
QMap<int, QMap<QString, QString>> parse_txt_to_test (const QString& path)
{
    QMap<int, QMap<QString, QString>> result;
    QMap<QString, QString> test_slide;
    QString word = "";
    QFile file(path);
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
        QApplication::exit();
    QTextStream in(&file);
    int counter_first = 0;
    while(!in.atEnd())
    {
        int counter = 0;
        QString line = in.readLine();
        for(int i = 0; i < line.size(); i++)
        {
            if(line[i] == '|')
            {
                switch(counter)
                {
                case 0:
                    test_slide["img"] = word;
                    word.clear();
                    break;
                case 1:
                    test_slide["question"] = word;
                    word.clear();
                    break;
                case 2:
                    test_slide["amount_of_questions"] = word;
                    word.clear();
                    break;
                case 3:
                    test_slide["number_of_right_answer"] = word;
                    word.clear();
                    break;
                case 4:
                    test_slide["variants_of_answers"] = word;
                    word.clear();
                    break;
                }
                counter++;
                continue;

            }

            word.append(line[i]);

        }
        result[counter_first] = test_slide;
        counter_first++;

    }
    return result;
}


QString read_needed_line_from_file(const QString& path, int num_of_line)
{
    QString word = "";
    QFile file(path);
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
        QApplication::exit();
    QTextStream in(&file);
    int counter = 0;
    while(!in.atEnd())
    {
        if(counter == num_of_line)
            word = in.readLine();
    }
    return word;

}


//parse line into (espessially in "variants_of_answers: ) strings and put it in QStringList
QStringList parse_line_into_questions(const QString &line)
{
    QStringList result;
    QString word;
    for(int i = 0; i < line.size(); ++i)
    {
        if( (line[i] == '/'))
        {
            result.append(word);
            word.clear();
            continue;
        }
        word.append(line[i]);
    }
    result.append(word);
    return result;
}


//writes QMap<int, QMap<QString, QString>> back in the file
void put_map_into_file(const QMap<int, QMap<QString, QString>>& map, QString path_to_txt_file)
{
    QFile file(path_to_txt_file);
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
        QApplication::exit();
    QTextStream in(&file);
    for(QMap<QString, QString> i : map)
    {
        in << i["img"] << "|" << i["question"] << "|" << i["amount_of_questions"] << "|" << i["number_of_right_answer"]
           << "|" << i["variants_of_answers"] << "|\n";
    }
}


//prints all test with all slides in qDebug
void print_test_in_debug(){
    QString path = "alltests/Test1/Test1.txt";
    QMap<int,QMap<QString, QString>> result = parse_txt_to_test(path);
    for(auto i = result.cbegin(), end = result.cend(); i != end; ++i)
    {
        for(auto j = i.value().cbegin(), end_j = i.value().cend(); j != end_j; ++j )
        {
            if(j.key() == "variants_of_answers")
            {
                qDebug() << j.key() << '\n';
                QStringList tmp = parse_line_into_questions(j.value());
                for(QString k : tmp)
                {
                    qDebug() << k << " ";
                }
                qDebug() << '\n';
                continue;
            }
            qDebug() << j.key() << " " << j.value() << '\n';

        }
        qDebug() << '\n';

    }
}


//checks, if it is avaiable to write QMap<int, QMap<QString, QString> > in file
bool is_avaiable_to_write_in_txt_file(const QMap<int, QMap<QString, QString> > &map)
{

    for(QMap<QString, QString> i : map)
    {
        if(i["amount_of_questions"] == "NONE" || i["number_of_right_answer"] == "NONE")
            return false;
    }
    return true;
}


QStringList count_files_in_dir(QString path)
{
    QDir directory(path);
    QStringList list_of_directories = directory.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);
    return list_of_directories;

}
