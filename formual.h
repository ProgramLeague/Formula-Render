#include<string>
#include<list>

enum formType {basic, sqrt, inte, frac, mat};

class maker;

class baseForm
{
private:
	bool verify()
	{
		return x1!=-1 && y1!=-1 && fontSize!=-1;
	}

public:
	virtual int getType()=0;
	virtual void draw()=0;
	float x1=-1;
	float y1=-1;
	int fontSize=-1;
	//父节点管理子节点所有权
	maker* supMaker=nullptr;
	maker* subMaker=nullptr;
	~formual()
	{
		delete supMaker;
		delete subMaker;
	}
};

class maker
{
private:
	bool makerFlag; //true为上标
	baseForm* form;
	
public:
	maker(bool markFlag, baseForm* form) : 
		markFlag(markFlag), form(form) {}
	void draw()
	{
		//fix:根据上下标计算form的三个量
		form->draw();
	}
	
	~marker()
	{
		delete form;
	}
};

class formual : public baseForm
{
private:
	string formStr;
	
public:
	int getType() { return basic; }
	formual(string formStr) : formStr(formStr) {}
	void draw();
};

class sqrtForm : public baseForm
{
private:
	baseForm* form;
	
public:
	int getType() { return sqrt; }
	sqrtForm(formual *form) : form(form) {}
	//这里应该加一个是根号或是什么的flag
	void draw();
	~sqrtForm()
	{
		delete form;
	}
};

class inteForm : public baseForm
{
private:
	baseForm* upper;
	baseForm* lower;
	baseForm* expr;
	
public:
	int getType() { return inte; }
	inteForm(baseForm* upper=nullptr, baseForm* lower=nullptr, baseForm* expr=nullptr) : 
		upper(upper), lower(lower), expr(expr) {}
	//这里应该加一个积分/求和积符号的flag
	void draw();
	~inteForm()
	{
		delete upper;
		delete lower;
		delete expr;
	}
};

class fracForm : public baseForm
{
private:
	baseForm* numForm;
	baseForm* denForm;
	
public:
	int getType() { return frac; }
	fracForm(baseForm* numForm, baseForm* denForm) : numForm(numForm), denForm(denForm) {}
	void draw();
	~fracForm()
	{
		delete numForm;
		delete denForm;
	}
};

class matForm : public baseForm
{
private:
	list<list<baseForm*>> allForm;

public:
	int getType() { return mat; }
	matForm(list<list<baseForm*>> allForm) : allForm(allForm) {}
	void draw();
	~matForm()
	{
		for(auto i : allForm)
		{
			for(baseForm* j : i)
				delete j;
		}
	}
};
