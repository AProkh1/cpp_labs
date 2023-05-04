//
//  Header.h
//  lab_4
//
//  Created by Антон Прохоров on 02/05/2023.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */

#pragma once

class BaseCObject
{
public:
    virtual const char* classname() const = 0;
    virtual unsigned int size() const = 0;
};

class CVector2D
{
public:
    double x, y;
};


class IGeoFig
{
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class IPhysObject
{
public:
    virtual double mass() const = 0;
    virtual CVector2D position() const = 0;
    virtual bool operator==(const IPhysObject& ob) const = 0;
    virtual bool operator<(const IPhysObject& ob) const = 0;
};

class IPrintable
{
public:
    virtual void draw() const = 0;
};

class IDialogInitiable
{
public:
    virtual void initFromDialog() = 0;
};

class EquilateralTriangle : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject
{
public:
    EquilateralTriangle();
    EquilateralTriangle(double a, double mass, const CVector2D& center_of_mass);

    double square() const override;
    double perimeter() const override;
    double mass() const override;
    CVector2D position() const override;
    bool operator==(const IPhysObject& ob) const override;
    bool operator<(const IPhysObject& ob) const override;
    void draw() const override;
    void initFromDialog() override;
    const char* classname() const override;
    unsigned int size() const override;

private:
    double a_;
    double mass_;
    CVector2D center_of_mass_;
};

class Ellipse : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {
    public:
    Ellipse();
    Ellipse(double R, double r, double mass, const CVector2D& center_of_mass);

    double square() const override;
    double perimeter() const override;
    double mass() const override;
    CVector2D position() const override;
    bool operator==(const IPhysObject& ob);
    bool operator<(const IPhysObject& ob);
    void draw() const override;
    void initFromDialog() override;
    const char* classname();
    unsigned int size();

private:
    double R_;
    double r_;
    double mass_;
    CVector2D center_of_mass_;
};
