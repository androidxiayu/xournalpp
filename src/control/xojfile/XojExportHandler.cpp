#include "XojExportHandler.h"

#include "control/jobs/ProgressListener.h"
#include "control/xml/XmlNode.h"
#include "control/xml/XmlTextNode.h"
#include "control/xml/XmlImageNode.h"
#include "control/xml/XmlTexNode.h"
#include "control/xml/XmlPointNode.h"
#include "model/Stroke.h"
#include "model/Text.h"
#include "model/Image.h"
#include "model/TexImage.h"
#include "model/Document.h"
#include "model/Layer.h"
#include "model/BackgroundImage.h"

#include <config.h>
#include <i18n.h>

#include <clocale>
#include <iostream>

using std::cout;
using std::endl;

XojExportHandler::XojExportHandler()
{
	XOJ_INIT_TYPE(XojExportHandler);
}

XojExportHandler::~XojExportHandler()
{
	XOJ_CHECK_TYPE(XojExportHandler);

	XOJ_RELEASE_TYPE(XojExportHandler);
}

void XojExportHandler::writeHeader()
{
	XOJ_CHECK_TYPE(XojExportHandler);

	this->root->setAttrib("creator", PROJECT_STRING);
	// Keept this version on 2, as this is anyway not read by Xournal
	this->root->setAttrib("fileversion", "2");
	this->root->addChild(new XmlTextNode("title", "Xournal document (Compatibility) - see " PROJECT_URL));
}

void XojExportHandler::writeSolidBackground(XmlNode* background, PageRef p)
{
	background->setAttrib("type", "solid");
	background->setAttrib("color", getColorStr(p->getBackgroundColor()));

	string format = p->getBackgroundType().format;

	if (format != "plain" && format != "lined" && format != "ruled" && format != "graph")
	{
		format = "plain";
	}

	background->setAttrib("style", format);
}

void XojExportHandler::writeTimestamp(Stroke* s, XmlPointNode* stroke)
{
	XOJ_CHECK_TYPE(XojExportHandler);	
	//Do nothing since timestamp are not supported by Xournal
}