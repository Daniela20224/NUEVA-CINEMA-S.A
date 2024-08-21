#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    int year;
    int duration; 
    std::string country;
    std::string review;

public:
    Movie(const std::string& name, int year, int duration, const std::string& country, const std::string& review);

    void showInformation() const;

    std::string getName() const;
    void setName(const std::string& name);

    int getYear() const;
    void setYear(int year);

    int getDuration() const;
    void setDuration(int duration);

    std::string getCountry() const;
    void setCountry(const std::string& country);

    std::string getReview() const;
    void setReview(const std::string& review);
};

#endif 