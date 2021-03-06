/**
 *  include/logger.h
 *
 *  (C) Copyright 2014 Michael Sippel
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @author Michael Sippel <michamimosa@gmail.com>
 */

#ifndef _DASYUR_LOGGER_H
#define _DASYUR_LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

class Logger;

enum log_type
{
    INFO,
    WARNING,
    ERROR
};

class LogData
{
        friend class Logger;

    public:
        LogData();
        LogData(enum log_type type_, char *text_);
        LogData(Logger *parent_, enum log_type type_, char *text_);
        ~LogData();

        char *getTypeString(void);
        char *getPrefixString(void);

    private:
        Logger *parent;

        enum log_type type;
        char text[256];
        time_t log_time;
};

class Logger
{
    public:
        Logger();
        Logger(const char *prefix_);
        Logger(char *prefix_);
        Logger(Logger *parent_, const char *prefix_);
        Logger(Logger *parent_, char *prefix_);
        ~Logger();

        List<LogData> *log_data;
        List<Logger> *sub_loggers;

        Logger *parent;
        char prefix[64];
        char prefix_str[256];

        void generate_prefix_str(char *prefix_);
        void log(enum log_type type, const char *text, ...);
};

#endif

