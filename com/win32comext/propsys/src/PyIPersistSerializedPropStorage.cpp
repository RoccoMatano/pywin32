// This file implements the IPersistSerializedPropStorage Interface for Python.
// Generated by makegw.py
#include "PythonCOM.h"
#include "propsys.h"
#include "PyIPersistSerializedPropStorage.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIPersistSerializedPropStorage::PyIPersistSerializedPropStorage(IUnknown *pdisp) : PyIUnknown(pdisp)
{
    ob_type = &type;
}

PyIPersistSerializedPropStorage::~PyIPersistSerializedPropStorage() {}

/* static */ IPersistSerializedPropStorage *PyIPersistSerializedPropStorage::GetI(PyObject *self)
{
    return (IPersistSerializedPropStorage *)PyIUnknown::GetI(self);
}

// @pymethod |PyIPersistSerializedPropStorage|SetFlags|Sets flags for the store
PyObject *PyIPersistSerializedPropStorage::SetFlags(PyObject *self, PyObject *args)
{
    IPersistSerializedPropStorage *pIPSPS = GetI(self);
    if (pIPSPS == NULL)
        return NULL;
    PERSIST_SPROPSTORE_FLAGS flags;
    // @pyparm int|flags||Combination of pscon.FPSPS_* values
    if (!PyArg_ParseTuple(args, "i:SetFlags", &flags))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIPSPS->SetFlags(flags);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIPSPS, IID_IPersistSerializedPropStorage);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIPersistSerializedPropStorage|SetPropertyStorage|Initializes the store with a serialized buffer
PyObject *PyIPersistSerializedPropStorage::SetPropertyStorage(PyObject *self, PyObject *args)
{
    IPersistSerializedPropStorage *pIPSPS = GetI(self);
    if (pIPSPS == NULL)
        return NULL;
    PyObject *obbuf;
    // @pyparm buffer|ps||Bytes or buffer object containing a serialized property store
    if (!PyArg_ParseTuple(args, "O:SetPropertyStorage", &obbuf))
        return NULL;
    BufferView pybuf(obbuf);
    if (!pybuf.ok())
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIPSPS->SetPropertyStorage((PUSERIALIZEDPROPSTORAGE)pybuf.ptr(), pybuf.len());
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIPSPS, IID_IPersistSerializedPropStorage);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod buffer|PyIPersistSerializedPropStorage|GetPropertyStorage|Retrieves the current contents of the property
// store
PyObject *PyIPersistSerializedPropStorage::GetPropertyStorage(PyObject *self, PyObject *args)
{
    IPersistSerializedPropStorage *pIPSPS = GetI(self);
    if (pIPSPS == NULL)
        return NULL;
    PUSERIALIZEDPROPSTORAGE buf;
    DWORD bufsize;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIPSPS->GetPropertyStorage(&buf, &bufsize);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIPSPS, IID_IPersistSerializedPropStorage);
    PyObject *ret = PyString_FromStringAndSize((char *)buf, bufsize);
    CoTaskMemFree(buf);
    return ret;
}

// @object PyIPersistSerializedPropStorage|Allows a property store to be marshalled into a single buffer.
//  Primarily used with property stores created using <om propsys.PSCreateMemoryPropertyStore>.
static struct PyMethodDef PyIPersistSerializedPropStorage_methods[] = {
    {"SetFlags", PyIPersistSerializedPropStorage::SetFlags, 1},  // @pymeth SetFlags|Sets flags for the store
    {"SetPropertyStorage", PyIPersistSerializedPropStorage::SetPropertyStorage,
     1},  // @pymeth SetPropertyStorage|Initializes the store with a serialized buffer
    {"GetPropertyStorage", PyIPersistSerializedPropStorage::GetPropertyStorage,
     METH_NOARGS},  // @pymeth GetPropertyStorage|Retrieves the current contents of the property store
    {NULL}};

PyComTypeObject PyIPersistSerializedPropStorage::type("PyIPersistSerializedPropStorage", &PyIUnknown::type,
                                                      sizeof(PyIPersistSerializedPropStorage),
                                                      PyIPersistSerializedPropStorage_methods,
                                                      GET_PYCOM_CTOR(PyIPersistSerializedPropStorage));
