#!/usr/bin/python3
import sys
import re


parsed_lines = []
lines = []
number_of_lines = {}
total_size = 0
codes = ['200', '301', '400', '401', '403', '404', '405', '500']


def lineparser(lines):
    for str in lines:
        try:
            get_split = str.split('"')
            date_split = get_split[0].split(' - ')
            ip = re.search("[0-9]+[.][0-9]+[.][0-9]+[.][0-9]+", date_split[0]).group()
            date = re.search("\[[0-9]{4}([-][0-9]{2}){2} ([0-9]{2}[:]){2}[0-9]{2}[.][0-9]+\]", date_split[1]).group()
            get = get_split[1]
            status_code = get_split[2].strip().split(' ')[0]
            size = get_split[2].strip().split(' ')[1]
            line = ''
            if (ip and date and get in str and status_code in codes and size):
                info = [status_code, size]
                parsed_lines.append(info)
                if status_code in number_of_lines:
                    number_of_lines[status_code] += 1
                else:
                    number_of_lines[status_code] = 1
        except:
            continue

for line in sys.stdin:
    lines.append(line)
    try:
        if (len(lines) == 10):
            lineparser(lines)
            for line in parsed_lines:
                total_size += int(line[1])
            lines = []
            print("File size: {}".format(total_size))
        for code in codes:
            try:
                print("{}: {}".format(code, number_of_lines[code]))
            except:
                continue
    except KeyboardInterrupt:
        lineparser(lines)
        for line in parsed_lines:
            total_size += int(line[1])
        lines = []
        print("File size: {}".format(total_size))
        for code in codes:
            try:
                print("{}: {}".format(code, number_of_lines[code]))
            except:
                continue
