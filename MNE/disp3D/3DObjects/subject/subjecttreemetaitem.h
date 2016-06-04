//=============================================================================================================
/**
* @file     subjecttreemetaitem.h
* @author   Lorenz Esch <Lorenz.Esch@tu-ilmenau.de>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     May, 2016
*
* @section  LICENSE
*
* Copyright (C) 2016, Lorenz Esch and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief     SubjectTreeMetaItem class declaration.
*
*/

#ifndef SUBJECTTREEMETAITEM_H
#define SUBJECTTREEMETAITEM_H

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "../../disp3D_global.h"
#include "../../helpers/abstracttreeitem.h"


//*************************************************************************************************************
//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QList>
#include <QVariant>
#include <QStringList>
#include <QColor>
#include <QStandardItem>
#include <QStandardItemModel>


//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include <Eigen/Core>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE DISP3DLIB
//=============================================================================================================

namespace DISP3DLIB
{


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================


//=============================================================================================================
/**
* SubjectTreeMetaItem provides a generic brain tree item to hold meta information about other brain tree items.
*
* @brief Provides a generic brain tree item.
*/
class DISP3DNEWSHARED_EXPORT SubjectTreeMetaItem : public AbstractTreeItem
{
    Q_OBJECT

public:
    typedef QSharedPointer<SubjectTreeMetaItem> SPtr;             /**< Shared pointer type for SubjectTreeMetaItem class. */
    typedef QSharedPointer<const SubjectTreeMetaItem> ConstSPtr;  /**< Const shared pointer type for SubjectTreeMetaItem class. */

    //=========================================================================================================
    /**
    * Default constructor.
    *
    * @param[in] iType      The type of the item. See types.h for declaration and definition.
    * @param[in] text       The text of this item. This is also by default the displayed name of the item in a view.
    */
    explicit SubjectTreeMetaItem(int iType = MetaTreeItemTypes::UnknownItem, const QString& text = "");

    //=========================================================================================================
    /**
    * Default destructor
    */
    ~SubjectTreeMetaItem();

    //=========================================================================================================
    /**
    * AbstractTreeItem functions
    */
    QVariant data(int role = Qt::UserRole + 1) const;
    void setData(const QVariant& value, int role = Qt::UserRole + 1);

signals:    
//    //=========================================================================================================
//    /**
//    * Emit this signal whenever the surface alpha value has changed.
//    *
//    * @param[in] fAlpha     The new alpha value.
//    */
//    void surfaceAlphaChanged(float fAlpha);
};

} //NAMESPACE DISP3DLIB

#endif // SUBJECTTREEMETAITEM_H