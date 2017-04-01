//
// Author: Timothy Baker
// cs361: Assignment 2
//"A story of Mites and Stars"
//
//node.cpp

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "node.h"

     ///////////////////////////////////////////////////////////////////
	// remove hatched eggs from egg list
     ///////////////////////////////////////////////////////////////////
	//
	void node::remove_hatchlings()
	{
		planet_eggs_itr=planet_eggs.begin();
		while(planet_eggs_itr!=planet_eggs.end())
		{
			if((*planet_eggs_itr)->get_hatched()==true)
			{
				mite* omeolet=*planet_eggs_itr;
				planet_eggs.remove(omeolet);
				planet_eggs_itr--;
			}
			planet_eggs_itr++;
		}
	}

     ///////////////////////////////////////////////////////////////////
	// let there be mite
     ///////////////////////////////////////////////////////////////////
	//
	void node::a_mite_is_born(list<mite>& mites)
	{
		// get mate
		planet_mites_itr=planet_mites.begin();
	 	mite* mate=*planet_mites_itr;
		planet_mites_itr++;
		(*planet_mites_itr)->mite_procreation(mites, planet_mites, mate, planet_eggs); 
	}

     ///////////////////////////////////////////////////////////////////
	// another mite bites the dust
     ///////////////////////////////////////////////////////////////////
	//
	// death to mites
	void node::death_to_mites(list<mite>& mites)
	{
		planet_mites.sort();
		planet_mites_itr=planet_mites.begin();
		mite* sucka=*planet_mites_itr;
		planet_mites.remove(sucka);
		mites.remove(*sucka);
	}

     ///////////////////////////////////////////////////////////////////
	// the saddest plot of our tale, poor little guys
     ///////////////////////////////////////////////////////////////////
	//
	// death to eggs
	void node::death_to_eggs(list<mite>& mites)
	{
		planet_eggs_itr=planet_eggs.begin();
		mite* sucka=*planet_eggs_itr;
		planet_mites.remove(sucka);
		mites.remove(*sucka);
		planet_eggs.remove(sucka);
	}
	
     ///////////////////////////////////////////////////////////////////
	// remove mites and stars that leave, bye bye and GodSpeed
     ///////////////////////////////////////////////////////////////////
	//
	// remove movers
	void node::remove_movers()
	{
		if(planet_stars.size()!=0)
		{
			planet_stars_itr=planet_stars.begin();
			while(planet_stars_itr!=planet_stars.end())
			{
				star* new_moon=*planet_stars_itr;
				star blood_moon=*new_moon;
				if(star_has_moved(blood_moon)==true)
				{
					planet_stars.remove(*planet_stars_itr);
					planet_stars_itr--;
				}
				planet_stars_itr++;
			}
		}	
		
		if(planet_mites.size()!=0)
		{
			planet_mites_itr=planet_mites.begin();
			while(planet_mites_itr!=planet_mites.end())
			{
				if(*planet_mites_itr==NULL){continue;}
				else
				{
					mite* fright_mite=*planet_mites_itr;
					mite mighty_mite=*fright_mite;
					if(mite_has_moved(mighty_mite)==true)
					{
						planet_mites.remove(*planet_mites_itr);
						planet_mites_itr--;
					}
					planet_mites_itr++;
				}
			}
		}
	}
	// find if the mite has moved by comparing x,y,z
	bool node::mite_has_moved(mite mite)
	{
		if(x==mite.get_x())
		{
			if(y==mite.get_y())
			{
				if(z==mite.get_z())
				{	
					return false;
				}
			}
		}
		return true;
	}
	// find if the star has moved by comparing x,y,z
	bool node::star_has_moved(star star)
	{
		if(x==star.get_x())
		{
			if(y==star.get_y())
			{
				if(z==star.get_z())
				{	
					return false;
				}
			}
		}
		return true;
	}


     ///////////////////////////////////////////////////////////////////
	// add new stars, welcome aboard. pick up your trash or get eaten
     ///////////////////////////////////////////////////////////////////
     //
     // add new mites
     void node::add_new_mites(list<mite>& mites)
     {
     	list<mite>::iterator mites_itr;
     	mites_itr=mites.begin();
     	while(mites_itr!=mites.end())
     	{
     	     if(mite_has_moved(*mites_itr)==false)
     	     {
     	     	if(mites_itr->get_hatched()==true)
     	     	{
     	     	     planet_mites.push_back(&*mites_itr);
     	     	     planet_mites.unique();
     	          }
     	     }
     	     mites_itr++;
     	}
     }
     // add new stars
     void node::add_new_stars(list<star>& stars)
     {
          list<star>::iterator stars_itr;
     	stars_itr=stars.begin();
     	while(stars_itr!=stars.end())
     	{
     		if(star_has_moved(*stars_itr)==false)
     		{
     		     planet_stars.push_back(&*stars_itr);
     	     	planet_stars.unique();
     	     }
     	     stars_itr++;
     	}
     }

