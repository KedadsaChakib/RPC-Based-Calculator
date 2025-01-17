/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calcul.h"

bool_t
xdr_data (XDR *xdrs, data *objp)
{
	register int32_t *buf;

	 if (!xdr_u_int (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_response (XDR *xdrs, response *objp)
{
	register int32_t *buf;

	 if (!xdr_u_int (xdrs, &objp->somme))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	return TRUE;
}
