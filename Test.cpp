#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "Paramedic.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"

namespace WarGame{

    TEST_CASE("Parameters check"){
        
        FootCommander* a = new FootCommander(2);
        CHECK(a->dmg==20);
        CHECK(a->hp==150);
        CHECK(a->player==2);

        FootSoldier* a1 = new FootSoldier(2);
        CHECK(a1->dmg==10);
        CHECK(a1->hp==100);
        CHECK(a1->player==1); 
        
        Paramedic* a2 = new Paramedic(5);
        CHECK(a2->dmg==0);
        CHECK(a2->hp==100);
        CHECK(a2->player==5);
        
        Sniper* a3 = new Sniper(1);
        CHECK(a3->dmg==50);
        CHECK(a3->hp==100);
        CHECK(a3->player==1);

        ParamedicCommander* a4 = new ParamedicCommander(5);
        CHECK(a4->dmg==0);
        CHECK(a4->hp==200);
        CHECK(a4->player==5);

        SniperCommander* a5 = new SniperCommander(2);
        CHECK(a5->dmg==100);
        CHECK(a5->hp==120);
        CHECK(a5->player==2);            
    
    }

    TEST_CASE("2"){

        Board p(6,6);
        CHECK_FALSE(p.has_soldiers(1));
        CHECK_FALSE(p.has_soldiers(2));
        p[{1,0}]= new Sniper(1);
        p[{1,1}]= new Sniper(2);
        p[{2,0}]= new FootSoldier(2);
        p[{2,1}]= new FootSoldier(2);
        p[{3,0}]= new FootCommander(1);
        p[{3,1}]= new FootCommander(1);
        p[{3,2}]= new FootCommander(1);
        p[{3,3}]= new FootCommander(1);
        p[{4,0}]= new ParamedicCommander(2);
        p[{5,0}]= new SniperCommander(2);
        p[{5,1}]= new SniperCommander(2);
        p[{6,0}]= new Paramedic(1);
        p[{6,1}]= new Paramedic(1);



        CHECK((p[{1,0}]->dmg) == 50);
        CHECK((p[{1,0}]->hp) == 100);
        CHECK((p[{1,1}]->hp) == 100);
        CHECK((p[{1,1}]->dmg) == 50);
        CHECK((p[{2,0}]->hp) == 100);
        CHECK((p[{2,0}]->dmg) == 10);
        CHECK((p[{2,1}]->hp) == 100);
        CHECK((p[{2,1}]->dmg) == 10);
        CHECK((p[{3,0}]->hp) == 150);
        CHECK((p[{3,0}]->dmg) == 20);
        CHECK((p[{3,1}]->hp) == 150);
        CHECK((p[{3,1}]->dmg) == 20);
        CHECK((p[{3,2}]->hp) == 150);
        CHECK((p[{3,2}]->dmg) == 20);
        CHECK((p[{3,3}]->hp) == 150);
        CHECK((p[{3,3}]->dmg) == 20);
        CHECK((p[{4,0}]->hp) == 200);
        CHECK((p[{4,0}]->dmg) == 0);
        CHECK((p[{5,0}]->hp) == 120);
        CHECK((p[{5,0}]->dmg) == 100);
        CHECK((p[{5,1}]->hp) == 120);
        CHECK((p[{5,1}]->dmg) == 100);
        CHECK((p[{6,0}]->hp) == 100);
        CHECK((p[{6,0}]->dmg) == 0);
        CHECK((p[{6,1}]->hp) == 100);
        CHECK((p[{6,1}]->dmg) == 0);
        CHECK((p[{5,5}]->hp) == 0);
        CHECK((p[{4,4}]->hp) == 0);
        CHECK((p[{4,3}]->hp) == 0);
        CHECK((p[{4,2}]->hp) == 0);
        CHECK((p[{4,1}]->hp) == 0);
        CHECK((p[{4,1}]->dmg) == 0);
        CHECK((p[{6,6}]->hp) == 0);
        CHECK((p[{6,6}]->dmg) == 0);
        CHECK((p[{6,5}]->hp) == 0);
        CHECK((p[{6,5}]->dmg) == 0);
        
        CHECK(p.has_soldiers(1));
        CHECK(p.has_soldiers(2));
        
        CHECK(p[{4,4}] == nullptr);
        CHECK(p[{4,1}] == nullptr);
        CHECK(p[{4,2}] == nullptr);
        CHECK(p[{4,3}] == nullptr);
        CHECK(p[{5,5}] == nullptr);
        CHECK(p[{5,1}] == nullptr);
        CHECK(p[{5,2}] == nullptr);
        CHECK(p[{5,3}] == nullptr);
        CHECK(p[{5,4}] == nullptr);
        CHECK(p[{5,5}] == nullptr);
        CHECK(p[{6,4}] == nullptr);
        CHECK(p[{6,5}] == nullptr);
        CHECK(p[{6,6}] == nullptr);
        
        CHECK(typeid(p[{6,0}])==typeid(Paramedic));
        CHECK(typeid(p[{6,1}])==typeid(Paramedic));
        CHECK(typeid(p[{4,0}])==typeid(ParamedicCommander));
        CHECK(typeid(p[{3,0}])==typeid(FootCommander));
        CHECK(typeid(p[{3,1}])==typeid(FootCommander));
        CHECK(typeid(p[{3,2}])==typeid(FootCommander));

    }

}
