#pragma once

#include <vector>
#include <string>

#include "flexui/Nodes/ContainerNode.hpp"
#include "flexui/Style/StyleEngine.hpp"
#include "flexui/Layout/LayoutEngine.hpp"
#include "flexui/Render/RenderEngine.hpp"
#include "flexui/Events/EventsController.hpp"

namespace flexui {

	class Element;
	class ResourceProvider;
	class TextureProvider;

	// A Document is the root for all other nodes
	class Document : public ContainerNode {
	public:
		Document(ResourceProvider* resource_provider, TextureProvider* texture_provider);
		~Document() override;

		std::string getNodeName() const override { return "#document"; }
		NodeType getNodeType() const override { return NodeType::DOCUMENT; };
		StyleEngine& getStyleEngine() { return m_StyleEngine; }
		LayoutEngine& getLayoutEngine() { return m_LayoutEngine; }
		RenderEngine& getRenderEngine() { return m_RenderEngine; }
		EventsController& getEventsController() { return m_EventController; }
		ResourceProvider* getResourceProvider() const { return m_ResourceProvider; }
		TextureProvider* getTextureProvider() const { return m_TextureProvider; }

		Element* findElementsAt(Node* node, const Vec2& point, std::vector<Element*>* found = nullptr);

	private:
		StyleEngine m_StyleEngine;
		LayoutEngine m_LayoutEngine;
		RenderEngine m_RenderEngine;
		EventsController m_EventController;

		ResourceProvider* m_ResourceProvider;
		TextureProvider* m_TextureProvider;
	};

}
