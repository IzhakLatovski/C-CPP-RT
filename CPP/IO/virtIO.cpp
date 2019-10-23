#include "virtIO.h"

using namespace std;

virtIO_t::~virtIO_t()
{
	close();
}

virtIO_t::virtIO_t()
{
	//Wm_file=;
	m_mode="/0";
	m_path="/0";
	m_status=ok_e;
	// position? length?
}

virtIO_t::virtIO_t(const string& name, const string& mode)
{
	m_status=open(name,mode);
	if(m_status==ok_e)
	{
		m_mode=mode;
		m_path=//path of file with 'name'
		// position? length?
	}
	else
	{
		//throw?
	}
}

status virtIO_t::open(const string& name, const string& mode)
{
	if((mode!="r") && (mode!="r+") && (mode!="w") && (mode!="w+"))
	{
		return bad_access_e;
	}
	if(!=(m_file=fopen(name,mode)))//?
	{
		return cant_open_file_e;
	}
	return ok_e;
}

void virtIO_t::close()
{
	if(m_status==ok_e)
	{
		fclose(m_file);
	}
}
