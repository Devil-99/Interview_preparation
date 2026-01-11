# System Design — README

This folder contains concise system-design writeups for common interview use cases. Each subdocument outlines the problem, core requirements, constraints, high-level architecture, key components, data considerations, scaling and reliability strategies, and important trade-offs. Use these notes to prepare design discussions, draw architectures, or as a starting point for deeper designs.

How to use:
- Read the short summary for each use case to understand scope and primary challenges.
- Expand any item into a full design by following the included key points (API, data model, components, scaling).
- Focus on trade-offs, capacity planning, and failure modes during interviews.

Use cases
- [ ] Google Search Engine  
    - Description: Large-scale web search and ranking for query results.  
    - Key points: web crawler, inverted index, ranking (TF-IDF/ML), sharding & replication, latency-sensitive caching, freshness & reindexing, query serving & autoscaling, monitoring and spam detection.

- [ ] Netflix  
    - Description: Video streaming service with personalization and global delivery.  
    - Key points: CDN + edge caching, adaptive bitrate streaming, microservices for content/catalog/user, personalization/recommendation ML, metadata DB + asset storage, traffic shaping & autoscaling, offline downloads DRM.

- [ ] Whatsapp  
    - Description: Real-time messaging with end-to-end encryption and presence.  
    - Key points: push notifications, persistent message queues, end-to-end encryption, message ordering & delivery receipts, presence & typing indicators, offline sync, federated connections and scalability, data retention policies.

- [ ] Amazon Order  
    - Description: E‑commerce order lifecycle: cart → checkout → fulfillment.  
    - Key points: eventual consistency for inventory, ACID transactions for checkout, order state machine, payment gateway integration, warehouse/fulfillment microservices, retry & idempotency, scaling for traffic spikes.

- [ ] Uber  
    - Description: Real-time matching of riders and drivers with geo-awareness.  
    - Key points: geospatial indexing (quadtrees/k-d), proximity search, real-time matching & surge pricing, routing & ETA, driver/rider state sync, dispatch microservices, fault tolerance & fallbacks.  
    - Resources: [Uber system design — YouTube](https://www.youtube.com/watch?v=gHIs0Mdow8M)  
    - Thumbnail: ![Uber system design thumbnail](https://img.youtube.com/vi/gHIs0Mdow8M/maxresdefault.jpg)

- [ ] Instagram  
    - Description: Photo/video sharing with feeds, stories, and social graph.  
    - Key points: feed generation (fan-out vs fan-in), media storage & thumbnails, CDN delivery, social graph scalability, notifications, strong/weak consistency trade-offs, rate limits & abuse detection.

- [ ] Spotify  
    - Description: Music streaming with large catalog, playlists, and recommendations.  
    - Key points: CDN for streaming, adaptive bitrate, playlist service, metadata & search, recommendation pipeline (offline/online), licensing & DRM, offline sync and caching.

- [ ] Dropbox  
    - Description: File sync and storage across devices with versioning.  
    - Key points: chunking/deduplication, block-level sync, conflict resolution and metadata store, encryption at rest/in transit, efficient delta sync, quota & billing, backup and version history.

- [ ] Airbnb  
    - Description: Marketplace for listings, bookings, and availability.  
    - Key points: listing search & filters, availability/calendar conflict resolution, booking transactions, pricing & reviews, host/renter verification, fraud detection, payments and cancellations.

- [ ] Tiktok  
    - Description: Short-form video platform with personalized short feed and real-time interactions.  
    - Key points: high-throughput media ingestion, recommendation ranking (low-latency), short-video encoding & CDN, social interactions & comments, moderation & content safety, ML feature pipelines.

- [ ] Pinterest  
    - Description: Visual discovery with pinning, boards, and recommendation.  
    - Key points: image indexing & deduplication, visual search, recommendation & recommendation storage, feed generation, scalability of user collections, search & tagging metadata.

- [ ] Zoom Call  
    - Description: Real-time audio/video conferencing at scale.  
    - Key points: WebRTC/RTC stack, media servers / SFU/MCU, NAT traversal, adaptive bitrate & packet-loss handling, latency and QoS, recording & storage, end-to-end encryption options, monitoring call quality.
    - Resources - [System Design Behind Multi-Conference Video Calls - WebRTC vs SFU vs MCU](https://www.youtube.com/watch?v=Zaz6hYVm-WE)
    - Thumbnail - ![Zoom Call system design thumbnail](https://i.ytimg.com/vi/Zaz6hYVm-WE/hqdefault.jpg)

- [ ] ChatGPT  
    - Description: Large language model-based conversational system with stateful sessions and inference serving.  
    - Key points: prompt handling & context windows, model serving (GPU/TPU), batching & caching responses, safety filters & moderation, fine-tuning and retrieval augmentation, latency vs cost trade-offs, logging and privacy.

- [ ] Paypal  
    - Description: Online payments and money transfers with high reliability and compliance.  
    - Key points: transactional guarantees, settlement & reconciliation, fraud detection, PCI compliance, idempotent APIs, multi-region redundancy, latency and throughput for payouts.

- [ ] Linkedin  
    - Description: Professional network with feeds, search, jobs, and notifications.  
    - Key points: social graph scale, feed ranking and personalization, search and people discovery, message/inmail service, job posting & matching, privacy controls and enterprise features.

- [ ] UPI  
    - Description: Instant payments infrastructure (immediate bank transfers) with real-time settlement.  
    - Key points: low-latency transactional APIs, strong authentication, settlement & clearing, idempotency & retries, fraud & risk controls, regulatory compliance, high availability and audit logging.

Notes on expansion
- For each use case, consider: functional vs non-functional requirements, bottlenecks, data models, API sketches, component diagrams, failure modes, and capacity estimates.
- When presenting designs, state assumptions explicitly and justify trade-offs.

Contributions
- Add or expand individual use-case files with architecture diagrams, sequence flows, and capacity planning notes.
