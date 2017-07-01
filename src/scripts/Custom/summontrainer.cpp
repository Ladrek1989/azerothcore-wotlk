#include "ScriptPCH.h"
#include "DisableMgr.h"
#include "Configuration/Config.h"
#include "ScriptMgr.h"


class summontrainer : public PlayerScript
{
public:

    summontrainer() : PlayerScript("summontrainer") {}

    void OnLevelChanged(Player* player, uint8 oldLevel)
    {
        switch (player->getClass())
        {
        case CLASS_DRUID:
        {
            if (player->getLevel() == 10) /*Bear form*/
            {
                player->learnSpell(5487);
                player->learnSpell(6795);
                player->learnSpell(6807);
                player->learnSpell(18960);
            }

            if (player->getLevel() == 16) /* Aqua Form*/
            {
                player->learnSpell(1066);
            }
            break;
        }
        case CLASS_SHAMAN:
        {
            if (player->getLevel() == 2) /* Earth Totem*/
            {
                player->learnSpell(8071);
                player->AddItem(46978, 1);
            }

            if (player->getLevel() == 10) /* Fire Totem */
            {
                player->learnSpell(3599);
            }

            if (player->getLevel() == 20) /* Water Totem*/
            {
                player->learnSpell(5394);
            }

            if (player->getLevel() == 30) /* Air Totem*/
            {
                player->AddAura(8385, player);
            }

            if (player->getLevel() == 70)
            {
                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    player->learnSpell(32182);
                }
                else
                    player->learnSpell(2825);
            }
            break;
        }  
        case CLASS_HUNTER:
        {

            if (player->getLevel() == 10) /* Learn Pets*/
            {
                player->learnSpell(1515); /* Tame Beast */
                player->learnSpell(883); /* Call Pet */
                player->learnSpell(2641); /* Dismiss Pet */
                player->learnSpell(6991); /* Feed Pet */
                player->learnSpell(982); /* Revive Pet */
            }
            break;
        }
        case CLASS_WARRIOR:
        {

            if (player->getLevel() == 10) /* Defensive Stance*/
            {
                player->learnSpell(71); 
                player->learnSpell(7386); /* Sunder Armor*/
                player->learnSpell(355);
            }

            if (player->getLevel() == 30) /* berserker stance*/
            {
                player->learnSpell(2458);
                player->learnSpell(20252);
            }
            break;
        }
        
        case CLASS_WARLOCK:
        {
            if (player->getLevel() == 10) /*Summon Void Walker*/
            {
                player->learnSpell(697);
            }

            if (player->getLevel() == 20) /* Summon Succubus */
            {
                player->learnSpell(712);
            }

            if (player->getLevel() == 30) /*Summon Felhunter*/
            {
                player->learnSpell(691);
            }
            break;
        }
        
        case CLASS_PALADIN:
        {
            if (player->getLevel() == 12)
            {
                player->learnSpell(7328);
            }

            if (player->getLevel() == 64)
            {
                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    player->learnSpell(31801); //Seal of Vengeance
                }
            }

            if (player->getLevel() == 20) /* Normal mount + Training*/
            {
                player->learnSpell(33388);
                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    player->learnSpell(13819);
                }
                else
                    player->learnSpell(34769);
            }

            if (player->getLevel() == 40)  /*Epic mount + Training*/
            {
                player->learnSpell(33391);
                if (player->GetTeamId() == TEAM_ALLIANCE)
                {
                    player->learnSpell(23214);
                }
                else
                {
                    player->learnSpell(34767); /*Horde*/
                }
            }

            if (player->getLevel() == 66)
            {
                if (player->GetTeamId() == TEAM_HORDE)
                {
                    player->learnSpell(53736); //Seal of Corruption
                }
            }
            break;
        }
        default:
            break;
        }
    }
};


void AddSC_Summontrainer()
{
    new summontrainer();
}