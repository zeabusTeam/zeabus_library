#!/usr/bin/env python2
# FILE			: read_file.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, September 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

class ReadFile:

    def __init__(self, name_file):
        self.name_file = name_file

    def count_line(self):
        document = open(self.name_file)
        count = len(document.readlines())
        document.close()
        return count

    def get_column(self, column, char):
        document = open(self.name_file)
        information = []
        for raw_data in document:
            data = raw_data.split(char)
            information.append(float(data[column]))
        document.close()
        return information
