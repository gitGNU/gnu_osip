/*
  The oSIP library implements the Session Initiation Protocol (SIP -rfc2543-)
  Copyright (C) 2001  Aymeric MOIZARD jack@atosc.org
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdlib.h>
#include <stdio.h>

#include <osip/port.h>
#include <osip/smsg.h>

int
to_init (to_t ** to)
{
  return from_init ((from_t **) to);
}

/* adds the to header to message.              */
/* INPUT : const char *hvalue | value of header.    */
/* OUTPUT: sip_t *sip | structure to save results.  */
/* returns -1 on error. */
int
msg_setto (sip_t * sip, char *hvalue)
{
  int i;

  if (sip->to != NULL)
    return -1;
  i = to_init (&(sip->to));
  if (i != 0)
    return -1;
#ifdef USE_TMP_BUFFER
  sip->message_property = 2;
#endif
  i = to_parse (sip->to, hvalue);
  if (i != 0)
    {
      to_free (sip->to);
      sfree (sip->to);
      sip->to = NULL;
      return -1;
    }
  return 0;
}

/* returns the to header.            */
/* INPUT : sip_t *sip | sip message.   */
/* returns null on error. */
to_t *
msg_getto (sip_t * sip)
{
  return sip->to;
}

int
to_parse (to_t * to, char *hvalue)
{
  return from_parse ((from_t *) to, hvalue);
}

/* returns the to header as a string.          */
/* INPUT : to_t *to | to header.  */
/* returns null on error. */
int
to_2char (to_t * to, char **dest)
{
  return from_2char ((from_t *) to, dest);
}

/* deallocates a to_t structure.  */
/* INPUT : to_t *to | to header. */
void
to_free (to_t * to)
{
  from_free ((from_t *) to);
}

int
to_clone (to_t * to, to_t ** dest)
{
  return from_clone ((from_t *) to, (from_t **) dest);
}
