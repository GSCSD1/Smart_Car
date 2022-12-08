/**
 *  \file  PID.c
 *
 *  \brief
 */

/*----------------------------------------------------------------------------
 *         头文件区
 *----------------------------------------------------------------------------*/
#include "PID.h"


/*----------------------------------------------------------------------------
 *        全局变量区
 *----------------------------------------------------------------------------*/
 PID sPID; 
 PID *sptr = &sPID; 

/*----------------------------------------------------------------------------
 *        函数定义区
 *----------------------------------------------------------------------------*/
/**********************************************************
*函数：void IncPID_Init(void)
*功能：PID 初值初始化     
*参数：无
*返回：无
*备注：无
**********************************************************/
void IncPID_Init(void) 
{ 
	sptr->SumError = 0; 
	sptr->LastError = 0;    //Error[-1] 
	sptr->PrevError = 0;    //Error[-2] 
    
    
	sptr->Proportion=8.2 ; //比例常数      越小变化越稳定   8
	sptr->Integral =0.9;   //积分常数       越小变化越慢   0.6
	sptr->Derivative =0.75;   //微分常数   //变化速度变快      0.7


}
 static double d_Error,dd_Error;
  double Error;

/**********************************************************
*函数：double IncPID_Calc(double SetPoint, double NextPoint)
*功能：PID 增量值计算     
*参数：无
*返回：无
*备注：无
**********************************************************/ 
double IncPID_Calc(double SetPoint, double NextPoint)                                                       //pid 算法实行
{ 
  
//	double iError, iIncpid;    //当前误差
//    
//	iError = SetPoint - NextPoint;        				//增量计算 
//	iIncpid = sptr->Proportion * iError   				//E[k]
//					- sptr->Integral * sptr->LastError    //E[k-1]
//					+ sptr->Derivative * sptr->PrevError; //E[k-2]

//	//存储误差，用于下次计算
//	sptr->PrevError = sptr->LastError; 
//	sptr->LastError = iError; 
    	double iError, iIncpid;
	Error     =  SetPoint - NextPoint;              // △e(k)
	d_Error   =  Error - sptr->LastError;                 // △e(k)-△e(k-1)
	dd_Error  =  d_Error - sptr->PrevError;	        // △e(k)-2*△e(k-1)+△e(k-2)
	sptr->LastError =  Error; 				         // △e(k-1)
	sptr->PrevError =  d_Error; 			       // △e(k-1)-△e(k-2)
    iIncpid    =  sptr->Proportion * d_Error  
	     	  +  sptr->Integral * Error       
	    	  + sptr->Derivative * dd_Error;
              
	return(iIncpid); 															//返回增量值
}

