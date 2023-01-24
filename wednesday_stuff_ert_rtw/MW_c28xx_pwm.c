#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "wednesday_stuff.h"
#include "wednesday_stuff_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1U;

  /*-- Configure pin assignments for ePWM1 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1U; /* Configure GPIOGPIO0 as EPWM1A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 0U;
  GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1U; /* Configure GPIOGPIO1 as EPWM1B*/
  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  EALLOW;
  volatile Uint32 tempRead = 0;

  /* Enable TBCLK after the ePWM configurations */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1U;
  EDIS;
}

void config_ePWMSyncSource (void)
{
  /* Configuring EXTSYNCOUT source selection */
  EALLOW;
  SyncSocRegs.SYNCSELECT.bit.SYNCOUT = 0U;

  /* Configuring ePWM Sync in source selection */
  SyncSocRegs.SYNCSELECT.bit.EPWM4SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM7SYNCIN = 0U;
  SyncSocRegs.SYNCSELECT.bit.EPWM10SYNCIN = 0U;
  EDIS;
}
