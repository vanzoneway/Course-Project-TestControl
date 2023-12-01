//readqfile.h
#ifndef READQFILE_H
#define READQFILE_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QDir>



QMap<int, QMap<QString, QString>> parse_txt_to_test (const QString& path);

void print_test_in_debug();

QStringList parse_line_into_questions(const QString& line);

void put_map_into_file(const QMap<int, QMap<QString, QString>>& map, QString path_to_txt_file);

bool is_avaiable_to_write_in_txt_file(const QMap<int, QMap<QString, QString>>& map);

QStringList count_files_in_dir(QString path);

#endif // READQFILE_H
