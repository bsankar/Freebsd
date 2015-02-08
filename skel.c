#include <sys/types.h>
#include<sys/module.h>
#include<sys/systm.h>
#include<sys/errno.h>
#include<sys/param.h>
#include<sys/kernel.h>

static int skel_loader(struct module *m,int what,void *arg)
{
int err=0;
switch(what){
case MOD_LOAD:
uprintf("Driver load succeeded");
break;
case MOD_UNLOAD:
uprintf("Driver unloaded");
break;
default:
err=EOPNOTSUPP;
break;
}
return err;
}

static moduledata_t skel_mod ={
"skel",skel_loader,NULL};

DECLARE_MODULE(skeleton,skel_mod,SI_SUB_KLD,SI_ORDER_ANY);
