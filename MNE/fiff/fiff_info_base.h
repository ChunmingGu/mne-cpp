//=============================================================================================================
/**
* @file     fiff_info_base.h
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     July, 2012
*
* @section  LICENSE
*
* Copyright (C) 2012, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of the Massachusetts General Hospital nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MASSACHUSETTS GENERAL HOSPITAL BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    FiffInfoBase class declaration.
*
*/

#ifndef FIFF_INFO_BASE_H
#define FIFF_INFO_BASE_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "fiff_global.h"
#include "fiff_types.h"
#include "fiff_ch_info.h"
#include "fiff_dig_point.h"
#include "fiff_ctf_comp.h"
#include "fiff_coord_trans.h"
#include "fiff_proj.h"


//*************************************************************************************************************
//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QList>
#include <QStringList>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QSharedPointer>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE FIFFLIB
//=============================================================================================================

namespace FIFFLIB
{


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================


//=============================================================================================================
/**
* Light measurement info -> ToDo transform this to FiffInfo base class for FiffInfo
*
* @brief light measurement info
*/
class FIFFSHARED_EXPORT FiffInfoBase
{
public:
    typedef QSharedPointer<FiffInfoBase> SPtr;              /**< Shared pointer type for FiffInfoBase. */
    typedef QSharedPointer<const FiffInfoBase> ConstSPtr;   /**< Const shared pointer type for FiffInfoBase. */

    //=========================================================================================================
    /**
    * Constructors the light fiff measurement file information.
    */
    FiffInfoBase();

    //=========================================================================================================
    /**
    * Copy constructor.
    *
    * @param[in] p_FiffInfoBase  light FIFF measurement information which should be copied
    */
    FiffInfoBase(const FiffInfoBase& p_FiffInfoBase);

    //=========================================================================================================
    /**
    * Destroys the light fiff measurement file information.
    */
    ~FiffInfoBase();

    //=========================================================================================================
    /**
    * Initializes light FIFF measurement information.
    */
    void clear();

    //=========================================================================================================
    /**
    * True if FIFF measurement file information is empty.
    *
    * @return true if FIFF measurement file information is empty
    */
    inline bool isEmpty() const;

    //=========================================================================================================
    /**
    * fiff_pick_channels
    *
    * ### MNE toolbox root function ###
    *
    * Make a selector to pick desired channels from data
    *
    * @param[in] ch_names  - The channel name list to consult
    * @param[in] include   - Channels to include (if empty, include all available)
    * @param[in] exclude   - Channels to exclude (if empty, do not exclude any)
    *
    * @return the selector matrix (row Vector)
    */
    static RowVectorXi pick_channels(const QStringList& ch_names, const QStringList& include = defaultQStringList, const QStringList& exclude = defaultQStringList);

    //=========================================================================================================
    /**
    * fiff_pick_info
    *
    * ### MNE toolbox root function ###
    *
    * Pick desired channels from measurement info
    *
    * @param[in] sel    List of channels to select
    *
    * @return Info modified according to sel
    */
    FiffInfoBase pick_info(const MatrixXi* sel = NULL) const;

    //=========================================================================================================
    /**
    * fiff_pick_types
    *
    * ### MNE toolbox root function ###
    *
    * ToDo meg: differ also between grad & mag
    * Create a selector to pick desired channel types from data
    *
    * @param[in] meg        Include MEG channels
    * @param[in] eeg        Include EEG channels
    * @param[in] stim       Include stimulus channels
    * @param[in] include    Additional channels to include (if empty, do not add any)
    * @param[in] exclude    Channels to exclude (if empty, do not exclude any)
    *
    * @return the selector matrix (row vector)
    */
    RowVectorXi pick_types(bool meg, bool eeg = false, bool stim = false, const QStringList& include = defaultQStringList, const QStringList& exclude = defaultQStringList) const;

public: //Public because it's a mne struct
    fiff_int_t  nchan;          /**< Number of channels. */
    QList<FiffChInfo> chs;      /**< List of all channel info descriptors. */
    QStringList ch_names;       /**< List of all channel names. */
    FiffCoordTrans dev_head_t;  /**< Coordinate transformation ToDo... */
    FiffCoordTrans ctf_head_t;  /**< Coordinate transformation ToDo... */
    QStringList bads;           /**< List of bad channels. */
};

//*************************************************************************************************************
//=============================================================================================================
// INLINE DEFINITIONS
//=============================================================================================================

inline bool FiffInfoBase::isEmpty() const
{
    return this->nchan <= 0;
}

} // NAMESPACE

#endif // FIFF_INFO_BASE_H