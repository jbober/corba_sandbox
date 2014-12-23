// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.1.5
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:376


#include "timeC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "timeC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:88

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const 
    _tao_fields_TimeOfDay[] =
      {
        { "hour", &CORBA::_tc_short },
        { "minute", &CORBA::_tc_short },
        { "second", &CORBA::_tc_short }
      };
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_TimeOfDay (
  ::CORBA::tk_struct,
  "IDL:TimeOfDay:1.0",
  "TimeOfDay",
  _tao_fields_TimeOfDay,
  3);

::CORBA::TypeCode_ptr const _tc_TimeOfDay =
  &_tao_tc_TimeOfDay;

// TAO_IDL - Generated from
// be/be_visitor_structure/structure_cs.cpp:59

void
TimeOfDay::_tao_any_destructor (
    void *_tao_void_pointer)
{
  TimeOfDay *_tao_tmp_pointer =
    static_cast<TimeOfDay *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:51

// Traits specializations for Time.

Time_ptr
TAO::Objref_Traits<Time>::duplicate (
    Time_ptr p)
{
  return Time::_duplicate (p);
}

void
TAO::Objref_Traits<Time>::release (
    Time_ptr p)
{
  ::CORBA::release (p);
}

Time_ptr
TAO::Objref_Traits<Time>::nil (void)
{
  return Time::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<Time>::marshal (
    const Time_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:91

::TimeOfDay
Time::get_gmt (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::TimeOfDay>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "get_gmt",
      7,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

Time::Time (void)
{
}

Time::~Time (void)
{
}

void
Time::_tao_any_destructor (void *_tao_void_pointer)
{
  Time *_tao_tmp_pointer =
    static_cast<Time *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

Time_ptr
Time::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Time>::narrow (
        _tao_objref,
        "IDL:Time:1.0");
}

Time_ptr
Time::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Time>::unchecked_narrow (
        _tao_objref);
}

Time_ptr
Time::_nil (void)
{
  return 0;
}

Time_ptr
Time::_duplicate (Time_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
Time::_tao_release (Time_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
Time::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:Time:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* Time::_interface_repository_id (void) const
{
  return "IDL:Time:1.0";
}

::CORBA::Boolean
Time::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:72

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_Time (
    ::CORBA::tk_objref,
    "IDL:Time:1.0",
    "Time");
  
::CORBA::TypeCode_ptr const _tc_Time =
  &_tao_tc_Time;

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_cs.cpp:46


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/// Copying insertion.
void operator<<= (
  ::CORBA::Any &_tao_any,
  const TimeOfDay &_tao_elem)
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<TimeOfDay *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<TimeOfDay>::insert_copy (
      _tao_any,
      TimeOfDay::_tao_any_destructor,
      _tc_TimeOfDay,
      _tao_elem);
}

/// Non-copying insertion.
void operator<<= (
  ::CORBA::Any &_tao_any,
  TimeOfDay *_tao_elem)
{
  TAO::Any_Dual_Impl_T<TimeOfDay>::insert (
    _tao_any,
    TimeOfDay::_tao_any_destructor,
    _tc_TimeOfDay,
    _tao_elem);
}

/// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
  const ::CORBA::Any &_tao_any,
  TimeOfDay *&_tao_elem)
{
  return _tao_any >>= const_cast<
      const TimeOfDay *&> (
      _tao_elem);
}

/// Extraction to const pointer.
::CORBA::Boolean operator>>= (
  const ::CORBA::Any &_tao_any,
  const TimeOfDay *&_tao_elem)
{
  return
    TAO::Any_Dual_Impl_T<TimeOfDay>::extract (
      _tao_any,
      TimeOfDay::_tao_any_destructor,
      _tc_TimeOfDay,
      _tao_elem);
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:41
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<Time>::to_object (
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    Time_ptr _tao_elem)
{
  Time_ptr _tao_objptr =
    Time::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    Time_ptr *_tao_elem)
{
  TAO::Any_Impl_T<Time>::insert (
      _tao_any,
      Time::_tao_any_destructor,
      _tc_Time,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    Time_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<Time>::extract (
        _tao_any,
        Time::_tao_any_destructor,
        _tc_Time,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_cs.cpp:52

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TimeOfDay &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.hour) &&
    (strm << _tao_aggregate.minute) &&
    (strm << _tao_aggregate.second);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TimeOfDay &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.hour) &&
    (strm >> _tao_aggregate.minute) &&
    (strm >> _tao_aggregate.second);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:54

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Time_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Time_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::Time RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (obj.in ());
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL


