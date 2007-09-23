#include "../../Core/helper.h"

CAttackBehaviour::CAttackBehaviour(Global* GL, boost::shared_ptr<IModule> unit){
	//
	G = GL;
	unit = unit;
	engaged = false;
	uid = ((CUnit*)unit.get())->GetID();
}

CAttackBehaviour::~CAttackBehaviour(){
	//
}

bool CAttackBehaviour::Init(boost::shared_ptr<IModule> me){
	//
	this->me = &me;
	return true;
}

void CAttackBehaviour::RecieveMessage(CMessage &message){
	if(message.GetType() == string("update")){
		if(EVERY_(120 FRAMES)){
			if(engaged){
				return;
			}
			float3 pos = G->GetUnitPos(uid);
			if(G->Map->CheckFloat3(pos)==false){
				return;
			}
			//if(G->Actions->CopyAttack(aa,Attackers)==false){
			if(G->Actions->AttackNear(uid, 3.5f) == false){
				//if(G->Actions->CopyMove(aa,Attackers)==false){
				/*if(walking.find(aa) == walking.end()){
				 //if(G->Actions->SeekOutInterest(aa,900.0f)==false){
				 //if(G->Actions->SeekOutLastAssault(aa)==false){
				 if(G->Actions->RandomSpiral(aa)==false){
				 //	G->Actions->ScheduleIdle(*aa);
				 }else{
				 walking.insert(aa);
				 }
				 //}else{
				 //	walking.insert(aa);
				 //}
				 //}else{
				 //	walking.insert(aa);
				 //}
				 }else{
				 return;
				 }*/
				//}else{
				//	walking.insert(aa);
				//}
			}else{
				engaged = true;
				// TODO: implement beacons using messaging system
				//Beacon(pos, 500.0f);
			}
		}
	}else if(message.GetType() == string("unitdestroyed")){
		if(message.GetParameter(0)== uid){
			End();
		}
	}
}

