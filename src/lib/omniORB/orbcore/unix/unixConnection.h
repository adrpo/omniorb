// -*- Mode: C++; -*-
//                            Package   : omniORB
// unixConnection.h           Created on: 6 Aug 2001
//                            Author    : Sai Lai Lo (sll)
//
//    Copyright (C) 2011 Apasphere Ltd.
//    Copyright (C) 2001 AT&T Laboratories Cambridge
//
//    This file is part of the omniORB library
//
//    The omniORB library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Library General Public
//    License as published by the Free Software Foundation; either
//    version 2 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Library General Public License for more details.
//
//    You should have received a copy of the GNU Library General Public
//    License along with this library; if not, write to the Free
//    Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//    02111-1307, USA
//
//
// Description:
//	*** PROPRIETARY INTERFACE ***
//

#ifndef __UNIXCONNECTION_H__
#define __UNIXCONNECTION_H__

#include <SocketCollection.h>

OMNI_NAMESPACE_BEGIN(omni)

class unixEndpoint;

class unixConnection : public giopConnection, public SocketHolder {
 public:

  int Send(void* buf, size_t sz,
	   const omni_time_t& deadline);

  int Recv(void* buf, size_t sz,
	   const omni_time_t& deadline);

  void Shutdown();

  const char* myaddress();

  const char* peeraddress();

  void setSelectable(int now = 0,CORBA::Boolean data_in_buffer = 0);

  void clearSelectable();

  CORBA::Boolean isSelectable();

  CORBA::Boolean Peek();

  SocketHandle_t handle() const { return pd_socket; }

  unixConnection(SocketHandle_t,SocketCollection*,
		 const char* filename, CORBA::Boolean isActive);

  ~unixConnection();

  static char* unToString(const char* filename);

  friend class unixEndpoint;

 private:
  CORBA::String_var pd_myaddress;
  CORBA::String_var pd_peeraddress;
};


class unixActiveConnection : public giopActiveConnection, public unixConnection {
public:
  giopActiveCollection* registerMonitor();
  giopConnection& getConnection();

  unixActiveConnection(SocketHandle_t,const char* filename);
  ~unixActiveConnection();

private:
  CORBA::Boolean pd_registered;

  unixActiveConnection(const unixActiveConnection&);
  unixActiveConnection& operator=(const unixActiveConnection&);
};


OMNI_NAMESPACE_END(omni)

#endif //__UNIXCONNECTION_H__
